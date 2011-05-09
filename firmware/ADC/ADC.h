// single mode
#define SGL 0b10000000

// reference voltage
#define V_LSB 3.3 / 1.024

void spi_initialize(void);
float adc_sample(unsigned char);
