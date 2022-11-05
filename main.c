/*
 * File:   main.c
 * Author: danie
 *
 * Created on 4. November 2022, 11:25
 */

#include "main.h"


struct
{
    unsigned int    PWM_duty;
    unsigned char   PWM_tab;
    unsigned char   Temperature;
}database; 


void main(void) 
{
    init();
    while (1)
    {
        
        database.Temperature = lm35_read();
        database.PWM_tab = dip_read();
        
        //database.PWM_tab = fan_update(database.Temperature);
        
    }
}
