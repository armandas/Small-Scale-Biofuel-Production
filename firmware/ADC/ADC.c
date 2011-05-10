#include <p18f66k22.h>
#include "ADC.h"
#include "../io.h"

void spi_initialize(void)
{
    // DDR
    TRISCbits.TRISC5 = 0;   // SDO
    TRISCbits.TRISC3 = 0;   // SCK

    // disable MSSP
    SSP1CON1bits.SSPEN = 0;

    SSP1CON1bits.SSPM = 0b0010; // SPI master mode, clock = Fosc/64
    SSP1CON1bits.CKP = 0;       // SCLK idles low
    SSP1STATbits.CKE = 1;       // transmit data on falling edge of the clock
    SSP1STATbits.SMP = 1;       // data input sample phase

    // enable MSSP
    SSP1CON1bits.SSPEN = 1;
}

float adc_sample(unsigned char channel)
{
    float adc_value = 0;
    unsigned char rx_data;

    // set CS pin as output
    ADC_CS_DDR = 0;
    // set CS low to enable the ADC
    ADC_CS = 0;

    // send start bit
    SSP1BUF = 1;
    while (SSP1STATbits.BF == 0);

    // sample channel in single-ended mode
    // and read two bits of the data
    SSP1BUF = SGL | (channel << 4);
    while (SSP1STATbits.BF == 0);
    rx_data = 0b11 & SSP1BUF;

    adc_value = (rx_data << 8);

    // read the rest of the data
    SSP1BUF = 0;
    while (SSP1STATbits.BF == 0);
    rx_data = SSP1BUF;

    adc_value += rx_data;

    // set CS high to disable the ADC
    ADC_CS = 1;

    adc_value *= V_LSB;

    return adc_value;
}
