#include <p18f66k22.h>
#include <delays.h>
#include "LCD/HD44780.h"
#include "menu/menu.h"

#pragma config FOSC = HS2       // HS oscillator (High power, 16 MHz - 25 MHz)
#pragma config PLLCFG = OFF     // PLL x4 Enable
#pragma config FCMEN = OFF      // disabled during debugging
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode
#pragma config PWRTEN = ON      // Power Up Timer
#pragma config BOREN = OFF      // Brown Out Detect
#pragma config WDTEN = OFF      // Watchdog Timer
#pragma config MCLRE = ON       // Master Clear Enable
#pragma config STVREN = OFF     // Stack Overflow Reset

#pragma code

void main(void)
{
    char buffer[LCD_CHARACTERS];

    unsigned char item;

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

    unsigned char arrow[8] = {
        0b00000,
    	0b01000,
    	0b01100,
    	0b01110,
    	0b01100,
    	0b01000,
    	0b00000,
    	0b00000
    };

    // all analog channels configured as digital i/o
    ANCON0 = 0;
    ANCON1 = 0;
    ANCON2 = 0;

    // keyboard
    TRISF = 0b00011110;

    lcd_initialize();
    lcd_add_character(1, degree);
    lcd_add_character(2, arrow);

    while (1) {
        item = menu();
        while (PORTFbits.RF4 == 1);
        Delay10KTCYx(50);
    }
}
