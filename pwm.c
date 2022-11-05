#include "pwm.h"

void pwm_init (void)
{
    PWM_TRIS |=     PWM_PIN;
    PWM_PORT &=   (~PWM_PIN);
    RA1PPS = 0x03;      // Port select (check!!!)
    
    PWM3CON = 0x00;
    PWM3DCH = 0x00;     // Duty 0%
    PWM3DCL = 0x00;     // Duty 0%
    
    PWM3CON |= POL;     // invert output
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