#include "menu.h"
#include "../LCD/HD44780.h"

const rom char * menu_items[MENU_LENGTH] = {
    "Start Process      ",
    "Info               ",
    "About              ",
    "Options            "
};

unsigned char menu(void)
{
    static unsigned char position = 0;
    unsigned char item = 0;

    unsigned char i;

    if (position == MENU_LENGTH)
        // reset position if the end of menu is reached
        position = 0;

    for (i = 0; i < LCD_LINES; i++) {
        // set the line for item display
        lcd_goto(i + 1, 1);

        // enable continuous rotation of items
        // i.e. item 1 follows the last item in the list
        item = (position + i > MENU_LENGTH - 1) ?
               ((position + i) - MENU_LENGTH) :
               (position + i);

        if (i == 0)
            // add an arrow to indicate current menu item
            lcd_write_pgm("\002");
        else
            // add a space to keep items aligned
            lcd_write_pgm(" ");

        // display menu item
        lcd_write_pgm(menu_items[item]);
    }
    // return current position and increment counter for the next call
    return position++;
}

