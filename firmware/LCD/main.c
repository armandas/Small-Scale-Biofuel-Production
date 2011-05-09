#include <p18cxxx.h>
#include <stdio.h>
#include <delays.h>
#include "HD44780.h"

#define MENU_LENGTH     5

#pragma config WDT = OFF
#pragma config PLLDIV = 4
#pragma config CPUDIV = OSC1_PLL2
#pragma config USBDIV = 2
#pragma config FOSC = HSPLL_HS
#pragma config BOR = OFF
#pragma config PBADEN = OFF
#pragma config PWRT = ON
#pragma config MCLRE = ON
#pragma config XINST = OFF

#pragma code

/******************************************************************************/

char menu(void);
const rom char * menu_items[MENU_LENGTH] = {
    "Start Process  ",
    "Info           ",
    "Options        ",
    "About          ",
    "LOLS           "
};

void main(void)
{
    char buffer[LCD_CHARACTERS];

    char item;

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

    // set RE2 as digital I/O
    ADCON1 = 0x08;

    // set ports as outputs
    TRISC = 0x00;
    DATA_DDR = 0x00;
    // tactile switch
    TRISE = 0x04;

    lcd_initialize();

    lcd_add_character(1, degree);
    lcd_add_character(2, arrow);

    item = menu();
    sprintf(buffer, "Selected item: %c", item);
    lcd_write(buffer);

    /*while (1) {
        while (PORTEbits.RE2 == 1);
        sprintf(message, "TC1:%d\001C TC2:%d\001C", position++, position2++);
        lcd_goto(1, 1);
        lcd_write(message);
    }*/
}

char menu(void)
{
    static unsigned char position = 0;
    unsigned char item = 0;

    unsigned char i;

    while (1) {
        if (position == MENU_LENGTH)
            position = 0;

        for (i = 0; i < LCD_LINES; i++) {
            lcd_goto(i + 1, 1);

            item = (position + i > MENU_LENGTH - 1) ? 0 : position + i;

            if (i == 0)
                lcd_write_pgm("\002");
            else
                lcd_write_pgm(" ");

            lcd_write_pgm(menu_items[item]);
        }
        position++;

        while (PORTEbits.RE2 == 1);
        Delay10KTCYx(255);
    }
    return 0;
}