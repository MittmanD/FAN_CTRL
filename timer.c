#include "timer.h"

timer_ticks timer_tick;

void timer2_init (void)
{
    OSCEN       |= MFOEN;               // Switch MFINTOSC on
    while(!(OSCSTAT & MFOR));           // Wait till MFINTOSC is stable
    T2CLKCON    = 0b00000001;           // HFINT/4 - must be this mode according to pwm spec
    T2HLT       = 0x00;                 // Software gate mode
    T2RST       = 0x00;                 // T2INPPS (Source ??????)
    T2PR        = 0xC6;                 // Timer 2 period
    T2TMR       = 0x00;
    PIE1        &= (~TMR2IE);           // Disable Timer 2 interrupt
    PIR1        &= (~TMR2IF);           // clear timer 2 interrupt flag
    T2CON       = 0b00100000;           // 1:128, 1:16, timer off
    T2CON       |= ON;                  // switch on timer 2
}

void timer0_init (void)
{
    OSCEN       |= 0x10;
    while(!(OSCSTAT & 0x10));          // Wait till LFINTOSC is stable
    T0CON0      = 0b00001111;
    T0CON1      = 0b01000000;      
    PIR0        &= (~0x20);
    T0CON0      |= 0x80;  
    PIE0        |= 0x20;
}

void timer0_isr (void)
{
    if (++timer_tick.count_10ms >= 10)
    {
        timer_tick.tick_10ms = 1;
        timer_tick.count_10ms = 0; 
    }
    if (++timer_tick.count_200ms >= 200)
    {
        timer_tick.tick_200ms = 1;
        timer_tick.count_200ms = 0; 
    }
    if (++timer_tick.count_1s >= 1000)
    {
        timer_tick.tick_1s = 1;
        timer_tick.count_1s = 0; 
    }
}

