#include "init.h"

void init (void)
{
    timer2_init();
    pwm_init();
    dip_init();
    adc_init();
}


