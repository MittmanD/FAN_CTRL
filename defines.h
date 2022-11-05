#include <xc.h>

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
extern void timer2_init (void);
extern void pwm_set (unsigned char pwm_duty);
extern void pwm_set_UI (unsigned int pwm_duty);
extern void fan_update (FAN *FAN_DB);
extern unsigned char lm35_read(void);
extern void fan_init (void);

extern FAN FAN_database;