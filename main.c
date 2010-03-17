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
    pwm_ramp1A(255, 10);
    for(;;){
        //simple test, runs through a few different commands
        _delay_ms(4000);
        pwm_ramp1A(0, 10);
        oh_crap();
        portB_out(2, 1);
        _delay_ms(500);
        portB_out(2, 0);
        all_good();
        pwm_ramp1A(255, 10);
    }
return 0;   //  never reached
}
