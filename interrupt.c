#include "interrupt.h"

void __interrupt() INTERRUPT_InterruptManager (void)
{
    if(INTCONbits.PEIE == 1)
    {
        if(PIE1bits.TX1IE == 1 && PIR1bits.TX1IF == 1)
        {
            EUSART1_TxDefaultInterruptHandler();
        } 
        else if(PIE1bits.RC1IE == 1 && PIR1bits.RC1IF == 1)
        {
            EUSART1_RxDefaultInterruptHandler();
        } 
        else if(PIE0bits.TMR0IE == 1 && PIR0bits.TMR0IF == 1)
        {
            timer0_isr();
            PIR0bits.TMR0IF = 0;
        } 
        else
        {
            __asm("nop");
            //Unhandled Interrupt
        }
    }      
    else
    {
        //Unhandled Interrupt
    }
}