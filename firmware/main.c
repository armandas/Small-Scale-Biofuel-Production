#include <p18f66k22.h>
#include <stdio.h>
#include <delays.h>
#include "io.h"
#include "main.h"
#include "LCD/HD44780.h"
#include "ADC/ADC.h"
#include "thermocouples/thermocouples.h"

#pragma config FOSC = HS2       // HS oscillator (High power, 16 MHz - 25 MHz)
#pragma config PLLCFG = ON      // PLL x4 Enable
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (disabled during debugging)
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode
#pragma config PWRTEN = ON      // Power Up Timer
#pragma config BOREN = OFF      // Brown Out Detect
#pragma config WDTEN = OFF      // Watchdog Timer
#pragma config MCLRE = ON       // Master Clear Enable
#pragma config STVREN = OFF     // Stack Overflow Reset
// Warning: DO NOT change the following configuration bits
#pragma config XINST = OFF      // Extended Instruction Set
#pragma config SOSCSEL = DIG    // SOSC Power Selection and mode Configuration

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
    _asm GOTO zero_crossing _endasm
}

#pragma interrupt zero_crossing
void zero_crossing(void)
{
    static unsigned char stage = 3;         // process stage
    static unsigned char power = 0;         // triac power level
    static unsigned char temp_limit = 78;
    static unsigned char counter = 99;
    static unsigned int seconds = 0;
    static unsigned char hours = 0;

    unsigned char buffer[LCD_CHARACTERS+1];
    int temp = 0;

    if (stage == 1 || stage == 2) {
        // control heater 1
        phase_fired_control(1, power);
    }
    else if (stage == 3) {
        // control heater 2
        phase_fired_control(2, power);
    }

    // measurements take a long time
    // so they are done only once every second.
    if (counter++ == 99) {
        // reset counter
        counter = 0;
        // update timing variables
        if (seconds++ == 3600) {
            seconds = 0;
            hours++;
        }

        if (stage == 0) {
            temp_limit = 50;
            stage = 1;
        }
        if (seconds == 300) {
            // first stage will last for 5 minutes
            temp_limit = 30;
            stage = 2;
        }
        else if (seconds == 600) {
            // second stage will last 5 minutes
            temp_limit = 78;
            stage = 3;
        }
        else if (seconds == 900) {
            stage = 4;
        }

        if (stage != 4) {
            // measure temperature here //
            temp = temperature(adc_sample(0), adc_sample(5));

            // adjust power level here //
            power = power_adjust(temp, temp_limit);

            lcd_goto(1, 1);
            sprintf(buffer, "Process stage: %d    ", stage);
            lcd_write(buffer);

            lcd_goto(2, 1);
            sprintf(buffer, "Power level: %3d%%   ", power);
            lcd_write(buffer);

            lcd_goto(3, 1);
            sprintf(buffer, "Heater temp: %2d\001C   ", temp);
            lcd_write(buffer);
        }
        else {
            lcd_clear();
            Delay10KTCYx(16);
            lcd_goto(1, 1);
            sprintf(buffer, "Heater test finished.");
            lcd_write(buffer);
        }
    }

    if (stage != 4) {
        INTCON3bits.INT1IF = 0; // clear INT1 interrupt flag
        //INTCON3bits.INT1IE = 1; // enable INT1 (ZCD) external interrupt
    }
}

#pragma code

void main(void)
{
    unsigned char buffer[LCD_CHARACTERS];

    unsigned char r = 1;

    unsigned char degree[8] = {
        0b01100,
    	0b10010,
    	0b10010,
    	0b01100,
    	0b00000,
    	0b00000,
    	0b00000,
    	0b00000
    };

    // all analog channels configured as digital i/o
    ANCON0 = 0;
    ANCON1 = 0;
    ANCON2 = 0;

    // keyboard
    TRISF = 0b00011110;

    // relay and TRIAC pins set as outputs
    RELAY1_DDR = 0;
    RELAY2_DDR = 0;
    RELAY3_DDR = 0;
    RELAY4_DDR = 0;
    RELAY5_DDR = 0;
    TRIAC1_DDR = 0;
    TRIAC2_DDR = 0;

    // startup delay
    Delay10KTCYx(255);
    Delay10KTCYx(255);

    lcd_initialize();
    spi_initialize();

    lcd_add_character(1, degree);

    lcd_goto(2, 1);
    lcd_write_pgm("Press OK to turn ON.");

    while (1) {
        switch (r) {
            case 1:
                RELAY1 = 1;
                RELAY2 = 0;
                RELAY3 = 0;
                RELAY4 = 0;
                RELAY5 = 0;
                break;
            case 2:
                RELAY2 = 1;
                RELAY1 = 0;
                RELAY3 = 0;
                RELAY4 = 0;
                RELAY5 = 0;
                break;
            case 3:
                RELAY3 = 1;
                RELAY1 = 0;
                RELAY2 = 0;
                RELAY4 = 0;
                RELAY5 = 0;
                break;
            case 4:
                RELAY4 = 1;
                RELAY1 = 0;
                RELAY2 = 0;
                RELAY3 = 0;
                RELAY5 = 0;
                break;
            case 5:
                RELAY5 = 1;
                RELAY1 = 0;
                RELAY2 = 0;
                RELAY3 = 0;
                RELAY4 = 0;
                break;
        }

        lcd_goto(1, 1);
        //lcd_write_pgm("Heater test.");
        sprintf(buffer, "Relay %d test.", r);
        lcd_write(buffer);

        while (DOWN_SWITCH);
        r = (r == 5) ? r = 1 : r + 1;
        Delay10KTCYx(255);
    }

    interrupt_initialize();

    //temperature_display();
    //lcd_clear();
}

void interrupt_initialize(void)
{
    // set pins as inputs
    TRISBbits.TRISB0 = 1;       // INT0 in RB0
    TRISBbits.TRISB1 = 1;       // INT1 on RB1

    RCONbits.IPEN = 0;          // disable interrupt priorities
    INTCONbits.GIE = 1;         // enable all interrupts
    INTCONbits.PEIE = 0;        // disable peripheral interrupts

    INTCON2bits.INTEDG0 = 0;    // INT0 interrupt on falling edge
    INTCON2bits.INTEDG1 = 1;    // INT1 interrupt on rising edge

    INTCONbits.INT0IF = 0;      // clear INT0 interrupt flag
    INTCONbits.INT0IE = 0;      // *disable* INT0 (RTC) external interrupt

    INTCON3bits.INT1IF = 0;     // clear INT1 interrupt flag
    INTCON3bits.INT1IE = 1;     // enable INT1 (ZCD) external interrupt
}

/**
 * Phase Fired Control
 *
 * Warning: delays are calculated for Fclk = 16MHz with PLL x4 enabled.
 *
 * @param channel - must be either 1 or 2
 * @param power - must be one of [100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0]
 */
void phase_fired_control(unsigned char channel, unsigned char power)
{
    switch (power) {
        case 100:
            // 0 ms
            break;
        case 90:
            // 2.3 ms
            Delay1KTCYx(36);
            Delay100TCYx(8);
            break;
        case 80:
            // 3.3 ms
            Delay1KTCYx(52);
            Delay100TCYx(8);
            break;
        case 70:
            // 4.1 ms
            Delay1KTCYx(64);
            Delay100TCYx(16);
            break;
        case 60:
            // 4.6 ms
            Delay1KTCYx(72);
            Delay100TCYx(16);
            break;
        case 50:
            // 5.4 ms
            Delay1KTCYx(84);
            Delay100TCYx(24);
            break;
        case 40:
            // 5.9 ms
            Delay1KTCYx(92);
            Delay100TCYx(24);
            break;
        case 30:
            // 6.6 ms
            Delay1KTCYx(106);
            Delay100TCYx(16);
            break;
        case 20:
            // 7.4 ms
            Delay1KTCYx(116);
            Delay100TCYx(24);
            break;
        case 10:
            // 8.2 ms
            Delay1KTCYx(128);
            Delay100TCYx(32);
            break;
        case 0:
            // do not turn on at all
            // fall through
        default:
            // defaults to OFF
            Delay1KTCYx(5);
            return;
            break;
    }

    if (channel == 1) {
        // pulse to TRIAC1 driver
        TRIAC1 = 1;
        Delay1KTCYx(20);
        TRIAC1 = 0;
    }
    else if (channel == 2) {
        // pulse to TRIAC2 driver
        TRIAC2 = 1;
        Delay1KTCYx(20);
        TRIAC2 = 0;
    }
}

unsigned char power_adjust(unsigned char temperature, unsigned char limit)
{
    // minimum limit is 25 degrees C
    if (limit < 25)
        return 0;

    if (temperature > limit)
        return 0;
    else if (temperature > (limit - 5))
        return 50;
    else if (temperature > (limit - 10))
        return 60;
    else if (temperature > (limit - 15))
        return 70;
    else if (temperature > (limit - 20))
        return 80;
    else if (temperature > (limit - 25))
        return 90;
    else
        return 100;
}
