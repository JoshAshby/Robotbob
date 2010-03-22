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
    pwm_setup_all();
    calibrate();
    for(;;)
    {
    }
return 0;   //  never reached
}
