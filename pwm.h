#include "defines.h"

#define EN          0x80
#define POL         0x10

#define PWM_INVERT

#define PWM_PORT    LATC       // 
#define PWM_TRIS    TRISC      // 
#define PWM_PIN     0x10       // Pin 5

#define PWM_MAX     1023.0f    // 10 bit max 0x03FF
#define DUTY_MAX    100.0f     // 100% max duty cycle
#define Fakt        ((float)(PWM_MAX / DUTY_MAX))

