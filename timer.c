#include "timer.h"


void timer2_init (void)
{
    OSCEN       |= MFOEN;           // Switch MFINTOSC on
    while(!(OSCSTAT & MFOR)){}      // Wait till MFINTOSC is stable
    T2CLKCON = 0b00000101;          // MFINTOSC (500 kHz)
    T2HLT = 0x00;                   // Software gate mode
    T2RST = 0x00;                   // T2INPPS (Source ??????)
    T2PR = 0xFF;                    // Timer 2 period
    T2TMR = 0x00;
    PIE1    &= (~TMR2IE);           // Disable Timer 2 interrupt
}

void timer2_start (void)
{
    
    
}

void timer2_isr (void)
{
    
    
}