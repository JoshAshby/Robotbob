#include "adc.h"
#include "pwm.h"
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
    pwm_setup();
    for(;;){
        pwm_ramp(255, 5);
        pwm_ramp(1, 10);
    }
return 0;   //  never reached
}
