#define RELAY1          LATAbits.LATA3
#define RELAY2          LATAbits.LATA2
#define RELAY3          LATAbits.LATA1
#define RELAY4          LATAbits.LATA0
#define RELAY5          LATAbits.LATA5
#define RELAY1_DDR      TRISAbits.TRISA3
#define RELAY2_DDR      TRISAbits.TRISA2
#define RELAY3_DDR      TRISAbits.TRISA1
#define RELAY4_DDR      TRISAbits.TRISA0
#define RELAY5_DDR      TRISAbits.TRISA5

#define TRIAC1          LATCbits.LATC1
#define TRIAC2          LATCbits.LATC0
#define TRIAC1_DDR      TRISCbits.TRISC1
#define TRIAC2_DDR      TRISCbits.TRISC0

#define UP_SWITCH       PORTFbits.RF2
#define DOWN_SWITCH     PORTFbits.RF1
#define OK_SWITCH       PORTFbits.RF4
#define ESC_SWITCH      PORTFbits.RF3

#define ADC_CS          LATDbits.LATD2
#define ADC_CS_DDR      TRISDbits.TRISD2

// register select
#define LCD_RS          LATEbits.LATE2
#define LCD_RS_DDR      TRISEbits.TRISE2
// read/write
#define LCD_RW          LATEbits.LATE1
#define LCD_RW_DDR      TRISEbits.TRISE1
// enable/clk
#define LCD_EN          LATEbits.LATE0
#define LCD_EN_DDR      TRISEbits.TRISE0
// backlight
#define LCD_BL_DDR      TRISGbits.TRISG4
#define LCD_BL          LATGbits.LATG4
// data port
#define LCD_DATA_DDR    TRISG
#define LCD_DATA_W      LATG