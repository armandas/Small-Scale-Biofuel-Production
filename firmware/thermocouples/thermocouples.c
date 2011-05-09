#include <p18f66k22.h>
#include <delays.h>
#include <stdio.h>
#include "../io.h"
#include "thermocouples.h"
#include "../LCD/HD44780.h"
#include "../ADC/ADC.h"

const rom float reference_coefficients[3] = {
    -0.017600,
     0.038921,
     0.000018,
};

const rom float inverse_coefficients[9] = {
     0.000000,
    25.083550,
     0.078601,
    -0.250313,
     0.083153,
    -0.012280,
     0.000980,
    -0.000044,
     0.000001,
};

int temperature(float thermocouple_voltage, int thermistor_voltage)
{
    // the thermocouple voltage is amplified
    // aproximatelly 300 times
    float v_tc = thermocouple_voltage / 300;
    float v_ref = reference_function(reference_temperature(thermistor_voltage));
    return inverse_function(v_tc + v_ref);
}

/** 
 * Converts tmepterature in °C to potential in mV
 */
float reference_function(float temperature)
{
    unsigned char i;
    float sum = 0;

    for (i = 0; i < 3; i++) {
        sum += reference_coefficients[i] * power(temperature, i);
    }
    return sum;
}

/**
 * Converts potential in mV to temperature in °C
 */
float inverse_function(float potential)
{
    unsigned char i;
    float sum = 0;

    for (i = 0; i < 9; i++) {
        sum += inverse_coefficients[i] * power(potential, i); 
    }
    return sum;
}

float power(float potential, unsigned char power)
{
    float result = 1;
    for (; power > 0; power--) {
        result *= potential;
    }
    return result;
}

/**
 * Returns the temperature at the refecence junction
 */
int reference_temperature(int thermistor_voltage)
{
    // adjust returned value using calibration offset
    return ((thermistor_voltage - 400) / 19.5)_CAL;
}

void temperature_display(void)
{
    char buffer[LCD_CHARACTERS];

    int t_ref, t_tc1, t_tc2, t_tc3, t_tc4, t_tc5 = 0;
    float v_tc1, v_tc2, v_tc3, v_tc4, v_tc5 = 0;
    int v_ref = 0;

    // while OK or ESC are not pressed
    // show temperatures
    while (OK_SWITCH && ESC_SWITCH) {
        v_tc1 = adc_sample(0);
        v_tc2 = adc_sample(1);
        v_tc3 = adc_sample(2);
        v_tc4 = adc_sample(3);
        v_tc5 = adc_sample(4);
        v_ref = adc_sample(5);

        t_ref = reference_temperature(v_ref);
        t_tc1 = temperature(v_tc1, v_ref);
        t_tc2 = temperature(v_tc2, v_ref);
        t_tc3 = temperature(v_tc3, v_ref);
        t_tc4 = temperature(v_tc4, v_ref);
        t_tc5 = temperature(v_tc5, v_ref);

        lcd_goto(1, 1);
        sprintf(buffer, "T0: %3d\001C  T3: %3d\001C", t_ref, t_tc3);
        lcd_write(buffer);
        lcd_goto(2, 1);
        sprintf(buffer, "T1: %3d\001C  T4: %3d\001C", t_tc1, t_tc4);
        lcd_write(buffer);
        lcd_goto(3, 1);
        sprintf(buffer, "T2: %3d\001C  T5: %3d\001C", t_tc2, t_tc5);
        lcd_write(buffer);

        // delay between measurements
        Delay10KTCYx(255);
        Delay10KTCYx(255);
        Delay10KTCYx(255);
        Delay10KTCYx(255);
    }
}