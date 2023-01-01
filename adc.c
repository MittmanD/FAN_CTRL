#include "adc.h"

void adc_init (void)
{
    // ADC
    analog_port &=    (~analog_pin);
    analog_tris |=      analog_pin;
    
    ADACT = 0x00;
    ANSELA      |=      0x04;           // RA2 = Analog Pin
    
        // FVRCON
    FVRCON = 0b10000001;                // Gain 1x (1,024V)
    while(!(FVRCON & 0x40)){}           // wait till stable
    ADCON1      =       0b11100011;     // connected to FVR
   // ADCON1      =       0b11100000;     // connected to FVR
    ADCON0      =       0b00001000; 
    ADCON0      |=      0x01;           // switch ADC on
}

unsigned int adc_read (void)
{
    ADCON0      |=      0x02;           // Start conversion
    while (ADCON0 & 0x02);
    return (((unsigned int) ADRESH) << 8) | ((unsigned int) ADRESL);
}