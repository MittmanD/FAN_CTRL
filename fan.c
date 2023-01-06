#include "fan.h"
#define FAN_TAB_COUNT       16
#define FAN_STEP_COUNT      21
#define FAN_TEMP_STEPS      2       // 2°C Schritte
#define TEMP_OFFSET         20
#define PWM_MIN_DUTY        10      //  10% minimum
#define PWM_MAX_DUTY       100      // 100% maximum

FAN FAN_database;
 

static const unsigned char fan_tab[FAN_TAB_COUNT][FAN_STEP_COUNT] =  
//   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
//  20°C 22°C 24°C 26°C 28°C 30°C 32°C 34°C 36°C 38°C 40°C 42°C 44°C 46°C 48°C 50°C 52°C 54°C 56°C 58°C 60°C 
{{  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 0
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 1
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 2
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 3
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 4
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 5
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 6
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 7
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 8
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 9
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 10
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 11
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 12
 {  10,  10,  10,  12,  14,  15,  17,  18,  20,  22,  25,  30,  35,  40,  50,  60,  70,  80,  90,  95, 100  },      // Index 13
 {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0  },      // Index 14:    All off
 { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100  }};     // Index 15:    All on
 
void fan_init (void)
{
    FAN_database.PWM_duty    = 0;
    FAN_database.index       = 0;
    FAN_database.FAN_tab     = 0;
}

void fan_update (FAN *FAN_DB)
{
    unsigned char TAB_index;
    if (FAN_DB->Temperature > TEMP_OFFSET)
    {
        TAB_index = (FAN_DB->Temperature - TEMP_OFFSET) / FAN_TEMP_STEPS; 
        if (TAB_index > (FAN_STEP_COUNT-1))
        {
            TAB_index = (FAN_STEP_COUNT-1);
        }
    }
    else
    {
        TAB_index = 0;
    }
    FAN_DB->PWM_duty    = (unsigned char)(fan_tab[FAN_DB->FAN_tab][TAB_index]);  
    FAN_DB->index       = TAB_index;
}
