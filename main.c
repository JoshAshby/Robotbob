#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
#include <util/delay.h>
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
    bios();
    pwm_ramp1A(255, 10);
    for(;;) {
        if (can_turn_left() == 1){
            turn_left();
        }
    }
return 0;   //  never reached
}
