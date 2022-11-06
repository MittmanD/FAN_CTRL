#include "interrupt.h"


void __interrupt() INTERRUPT_InterruptManager (void)
{
    if(INTCONbits.PEIE == 1)
    {
        if(PIE1bits.ADIE == 1 && PIR1bits.ADIF == 1)
        {
            //ADC_ISR();
        } 
        else if(PIE1bits.TX1IE == 1 && PIR1bits.TX1IF == 1)
        {
            EUSART1_TxDefaultInterruptHandler();
        } 
        else if(PIE1bits.RC1IE == 1 && PIR1bits.RC1IF == 1)
        {
            EUSART1_RxDefaultInterruptHandler();
        } 
        else
        {
            //Unhandled Interrupt
        }
    }      
    else
    {
        //Unhandled Interrupt
    }
}