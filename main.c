#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include <avr/delay.h>
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
int adcv;
//-------------------------------------------
/*
Main.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
int main(void)
{
    setup();
    pwm_setup2();
    calibrate();
    for(;;)
    {
        if (ultrasound_filter(4) > base)
        {
            out('D', 2, 0);
            pwm2B(ultrasound_filter(5));
        }
        else
        {
            out('D', 2, 1);
            pwm2B(ultrasound_filter(4));
        }
    }
return 0;   //  never reached
}
