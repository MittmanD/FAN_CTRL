#include "lm35.h"

// 10mV pro °C
unsigned char lm35_read(void)
{
    unsigned int Temp;
    Temp = adc_read();
    Temp /= 10;
    return ((unsigned char) Temp);
}
