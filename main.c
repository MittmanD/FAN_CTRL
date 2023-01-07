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
        if (timer_tick.tick_1s)
        {
            FAN_database.FAN_tab        = dip_read();
            FAN_database.Temperature    = lm35_read();
            
            fan_update(&FAN_database);
            pwm_set(FAN_database.PWM_act_duty);
            
            printf("[TE]%u\n", FAN_database.Temperature);
            printf("[DA]%u\n", FAN_database.PWM_act_duty);
            printf("[DT]%u\n", FAN_database.PWM_tar_duty);
            printf("[IX]%u\n", FAN_database.FAN_tab);
            
            timer_tick.tick_1s = 0;
        }
        
        if (timer_tick.tick_200ms)
        {    
            led_toggle();
            timer_tick.tick_200ms = 0;
        } 
    }
}

