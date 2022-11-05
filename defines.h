#include <xc.h>

extern void init (void);
extern void pwm_init (void);
extern void dip_init (void);
extern unsigned char dip_read (void);
extern void adc_init (void);
extern void timer2_init (void);
extern void pwm_set (unsigned int pwm_duty);
extern struct FAN fan_update (unsigned char temperature, unsigned char tab);
extern unsigned char lm35_read(void);

