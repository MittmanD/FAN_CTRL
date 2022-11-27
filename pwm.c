#include "pwm.h"

void pwm_init (void)
{
    PWM_TRIS &=   (~PWM_PIN);
    PWM_PORT &=   (~PWM_PIN);
    RC5PPS = 0x03;      // Port select (check!!!)
    
    PWM3CON = 0x00;
    PWM3DCH = 0x00;     // Duty 0%
    PWM3DCL = 0x00;     // Duty 0%
    
#ifdef PWM_INVERT
    PWM3CON |= POL;     // invert output
#else
    PWM3CON &= (~POL);  // non inverting output
#endif
    PWM3CON |= EN;      // PWM enable
}

void pwm_set (unsigned char pwm_duty)
{
    pwm_set_UI((unsigned int)(Fakt * ((float)pwm_duty)));
}

void pwm_set_UI (unsigned int pwm_duty)
{
     PWM3DCH = (unsigned char)((pwm_duty & 0x03FC) >> 2);
     PWM3DCL = (unsigned char)((pwm_duty & 0x0003) << 6);
}