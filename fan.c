#include "fan.h"
#define FAN_TAB_COUNT       3
#define FAN_STEP_COUNT      21
#define FAN_TEMP_STEPS      2       // 2°C Schritte
#define TEMP_OFFSET         20
#define PWM_MIN_DUTY        10      //  10% minimum
#define PWM_MAX_DUTY       100      // 100% maximum

typedef struct FAN
{
    unsigned int    PWM_duty;
    unsigned char   FAN_tab;
    unsigned char   index;
};
                 
static const unsigned char fan_tab[FAN_TAB_COUNT][FAN_STEP_COUNT] =  
//   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
//  20°C 22°C 24°C 26°C 28°C 30°C 32°C 34°C 36°C 38°C 40°C 42°C 44°C 46°C 48°C 50°C 52°C 54°C 56°C 58°C 60°C 
{{  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 0
 {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0  },      // Index 1: All off
 { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100  }};     // Index 2: All on

void fan_init (void)
{
    unsigned char TAB_index;
    
}

struct FAN fan_update (unsigned char temperature, unsigned char tab)
{
    unsigned char TAB_index;
    struct FAN fan_temp;
    if (temperature > TEMP_OFFSET)
    {
        TAB_index = (temperature - TEMP_OFFSET) / 2; 
        if (TAB_index > (FAN_STEP_COUNT-1))
        {
            TAB_index = (FAN_STEP_COUNT-1);
        }
    }
    else
    {
        TAB_index = 0;
    }
    
    fan_temp.index = TAB_index;
    fan_temp.PWM_duty = fan_tab[tab][TAB_index];
    return fan_temp;
}
