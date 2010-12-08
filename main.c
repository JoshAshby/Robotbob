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
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
int temp;
int main(void)
{
    bios();
    //pwm_ramp1A(255, 10);
    for(;;) {

        temp = (PIND & 0x0c);
        if (temp == 1){
            portB_out(1,1);
        }
        if (temp == 0){
            portB_out(1,0);
        }

/*        _delay_ms(7000);
        if (ultrasound_filter(4) > 100 && ultrasound_filter(5) > 100){
            turn_left();
        }
        else if (ultrasound_filter(4) < 90 && ultrasound_filter(5) < 90){
            turn_right();
        }*/
    }
return 0;   //  never reached
}
