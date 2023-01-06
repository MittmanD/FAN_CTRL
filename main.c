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
        //pwm_set(100);       // +++++++++++++++++++++++++++
   
        if (timer_tick.tick_1s)
        {
            FAN_database.FAN_tab        = dip_read();
            FAN_database.Temperature    = lm35_read();
            
            fan_update(&FAN_database);
            pwm_set(FAN_database.PWM_duty);
            
            printf("Temp: %u\n", FAN_database.Temperature);
            printf("Duty: %u\n", FAN_database.PWM_duty);
            printf("Tab: %u\n", FAN_database.FAN_tab);
            //led_set(1);
            
            timer_tick.tick_1s = 0;
        }
        
        if (timer_tick.tick_200ms)
        {    
            led_toggle();
            timer_tick.tick_200ms = 0;
        } 
    }
}

