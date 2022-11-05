#include "lm35.h"
#define     VREF                1024.0f     // 1,024 V Referenz    
#define     ADRESOLUTION        1024.0f     // 10 Bit Auflösung

// 10mV pro °C

unsigned char lm35_read(void)
{
    unsigned int Temp;
    Temp = adc_read();
    Temp /= 10;
    return ((unsigned char) Temp);
}
