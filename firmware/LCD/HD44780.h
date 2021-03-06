/******************************* CONFIG ***************************************/

// number of lines on the LCD
#define LCD_LINES       4
#define LCD_CHARACTERS  20

// data mask
// this must match the data pins on the port
// this program uses 4 lower bits of PORT G
#define DATA_MASK 0b00001111

// BUSY flag is output to DB7
// set mask according to your config
// normally, the MSB of DATA_MASK
//#define BUSY 0b00001000

/******************************* END OF CONFIG ********************************/

// commands
#define CLEAR_DISPLAY           0x01
#define RETURN_HOME             0x02
#define ENTRY_MODE              0x04
#define DISPLAY_CONTROL         0x08
#define CURSOR_DISPLAY_SHIFT    0x10
#define FUNCTION_SET            0x20
#define SET_CGRAM_ADDR          0x40
#define SET_DDRAM_ADDR          0x80

// ENTRY_MODE flags
#define CURSOR_INCREMENT        0x02
#define ENABLE_SHIFTING         0x01

// DISPLAY_CONTROL flags
#define DISPLAY_ON              0x04
#define CURSOR_ON               0x02
#define BLINKING_ON             0x01

// CURSOR_DISPLAY_SHIFT flags
#define DISPLAY_SHIFT           0x08
#define SHIFT_RIGHT             0x04

// FUNCTION_SET flags
#define DATA_LENGTH             0x10
#define DISPLAY_LINES           0x08
#define CHAR_FONT               0x04


// function prototypes
void _send_nibble(unsigned char);
void _send_byte(unsigned char);

void lcd_flags_set(unsigned char, unsigned char, unsigned char);
void lcd_initialize(void);
void lcd_command(unsigned char);
void lcd_data(unsigned char);
void lcd_write(char *);
void lcd_write_pgm(const rom char *);
void lcd_goto(unsigned char, unsigned char);
void lcd_add_character(unsigned char, unsigned char *);

// inline functions
#define lcd_clear()         lcd_command(CLEAR_DISPLAY)
#define lcd_return_home()   lcd_command(RETURN_HOME)
#define lcd_display_on()    lcd_flags_set(DISPLAY_CONTROL, DISPLAY_ON, 1)
#define lcd_display_off()   lcd_flags_set(DISPLAY_CONTROL, DISPLAY_ON, 0)
#define lcd_cursor_on()     lcd_flags_set(DISPLAY_CONTROL, CURSOR_ON, 1)
#define lcd_cursor_off()    lcd_flags_set(DISPLAY_CONTROL, CURSOR_ON, 0)
#define lcd_blinking_on()   lcd_flags_set(DISPLAY_CONTROL, BLINKING_ON, 1)
#define lcd_blinking_off()  lcd_flags_set(DISPLAY_CONTROL, BLINKING_ON, 0)
#define lcd_backlight_on()  LCD_BL = 1
#define lcd_backlight_off() LCD_BL = 0
