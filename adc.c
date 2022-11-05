#include "adc.h"

void adc_init (void)
{
    // FVRCON
    FVRCON = 0b10000001;                // Gain 1x (1,024V)
    while(!(FVRCON & 0x40)){}           // wait till stable
    
    // ADC
    analog_port &=    (~analog_pin);
    analog_tris |=      analog_pin;
    ANSELA      |=      0x01;           // RA0 = Analog Pin
    ADCON1      =       0b11100011;     // connected to FVR
    ADCON0      =       0b00000000; 
    ADCON0      |=      0x01;           // switch ADC on
}

unsigned int adc_read (void)
{
    ADCON0      |=      0x02;           // Start conversion
    while (ADCON0 & 0x02){}
    return ((unsigned int)(((ADRESH << 8) + ADRESL)) & 0x03FF);
}