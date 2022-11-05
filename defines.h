#include <xc.h>

extern void init (void);
extern void pwm_init (void);
extern void dip_init (void);
extern void adc_init (void);
extern void timer2_init (void);

typedef struct
{
    unsigned int    PWM_duty;
    unsigned char   PWM_tab;
    unsigned char   Temperature;
    
    
}database;