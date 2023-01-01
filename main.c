/*
 * File:   main.c
 * Author: danie
 *
 * Created on 4. November 2022, 11:25
 */

#include "main.h"

void main(void) 
{
    init();
    while (1)
    {
        FAN_database.Temperature    = lm35_read();
        FAN_database.FAN_tab        = dip_read();
        //fan_update(&FAN_database);
       // pwm_set(FAN_database.PWM_duty);
        pwm_set(100);       // +++++++++++++++++++++++++++
        
        printf("Hello world");
        //EUSART1_Write(43);
        
    }
}

