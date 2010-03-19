#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include <avr/delay.h>
#include "boot.h"
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
    for(;;){
        //simple test, runs through a few different commands
        adc_change(4);
        pwm2B(ADCH);
    }
return 0;   //  never reached
}
