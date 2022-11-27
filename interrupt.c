#include "interrupt.h"

#define PWM_PORT    LATC       // Pr�fen!
#define PWM_TRIS    TRISC      // Pr�fen!
#define PWM_PIN     0x04       // Pr�fen!

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
        else if(PIE1bits.TMR2IE == 1 && PIR1bits.TMR2IF == 1)
        {
            //PWM_PORT ^=   PWM_PIN;
            PIR1bits.TMR2IF = 0;
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