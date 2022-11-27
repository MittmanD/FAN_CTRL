/*
 * File:   main.c
 * Author: danie
 *
 * Created on 4. November 2022, 11:25
 */

#include "main.h"

#define PWM_PORT    LATC       // Pr�fen!
#define PWM_TRIS    TRISC      // Pr�fen!
#define PWM_PIN     0x04       // Pr�fen!

void main(void) 
{
    init();
    PWM_TRIS &=   (~PWM_PIN);
    //pwm_set_UI(0xFF);
    while (1)
    {
        //FAN_database.Temperature = lm35_read();
       // FAN_database.FAN_tab = dip_read();
        //fan_update(&FAN_database);
       // pwm_set(FAN_database.PWM_duty);
        //pwm_set(0x7F);       // +++++++++++++++++++++++++++
        PWM_PORT  |= PWM_PIN;
        PWM_PORT  &= (~PWM_PIN);
    }
}
