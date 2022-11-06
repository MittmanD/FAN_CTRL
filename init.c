#include "init.h"

void init (void)
{
    OSCFRQ      = 0b00000100;
    OSCTUNE     = 0x00;
    OSCEN       = 0b01010000;
    WDTCON      = 0x00;
    
    while(!(OSCSTAT & 0x40)){}      // wait till HFINTOSC ist stable
    INTCON      = 0x00;
    
    PIE0        = 0x00;
    PIE1        = 0x00;
    PIE2        = 0x00;
    PIR0        = 0x00;
    PIR1        = 0x00;
    PIR2        = 0x00;
    
    BORCON      = 0b10000000;
    PCON0       = 0b00011111;
    PCON1       = 0b00000010;
    
    timer2_init();
    pwm_init();
    dip_init();
    adc_init();
    fan_init();
    EUSART1_Initialize();
    
    pwm_set(0); 
    INTCON |= 0x40;
    INTCON |= 0x80;
}


