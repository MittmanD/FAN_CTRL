#include <xc.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct 
{
    unsigned int tick_10ms          :1;
    unsigned int tick_200ms         :1;
    unsigned int tick_1s            :1;
    unsigned char count_10ms;
    unsigned char count_200ms;
    unsigned int  count_1s;
}timer_ticks;

typedef struct
{
    unsigned char   PWM_duty;
    unsigned char   FAN_tab;
    unsigned char   index;
    unsigned char   Temperature;
}FAN;

extern void init (void);
extern void pwm_init (void);
extern void dip_init (void);
extern unsigned char dip_read (void);
extern void adc_init (void);
extern unsigned int adc_read (void);
extern unsigned int adc_read_mean (void);
extern void timer2_init (void);
extern void pwm_set (unsigned char pwm_duty);
extern void pwm_set_UI (unsigned int pwm_duty);
extern void fan_update (FAN *FAN_DB);
extern unsigned char lm35_read(void);
extern void fan_init (void);

extern void EUSART1_Initialize(void);
extern bool EUSART1_is_tx_ready(void);
extern bool EUSART1_is_rx_ready(void);
extern bool EUSART1_is_tx_done(void);
extern uint8_t EUSART1_Read(void);
extern void EUSART1_Write(uint8_t txData);
extern void putch(char txData);
extern void EUSART1_Transmit_ISR(void);
extern void EUSART1_Receive_ISR(void);
extern void (*EUSART1_TxDefaultInterruptHandler)(void);
extern void (*EUSART1_RxDefaultInterruptHandler)(void);
extern void led_set (unsigned char state);
extern void led_toggle (void);
extern void led_init (void);
extern void timer0_init (void);
extern void timer0_isr (void);



extern FAN FAN_database;
extern timer_ticks timer_tick;

