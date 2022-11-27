#include "defines.h"

#define EN          0x80
#define POL         0x10

//#define PWM_INVERT

#define PWM_PORT    LATC       // Pr�fen!
#define PWM_TRIS    TRISC      // Pr�fen!
#define PWM_PIN     0x20       // Pr�fen!

#define PWM_MAX     1023.0f    // 10 bit max 0x03FF
#define DUTY_MAX    100.0f     // 100% max duty cycle
#define Fakt        (PWM_MAX / DUTY_MAX)
