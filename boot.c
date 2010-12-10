//-------------------------------------------
/*
Boot.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

void error(char type) {
    switch (type) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
    }
}
void bios(void) {
    DDRD |= (1<<statPower);//LED power
    DDRD |= (1<<Stat1);//LED Status
    DDRD |= (1<<Trelay);//relay back
    DDRD |= (1<<Drelay);//relay front
    //CPU_POW goes here
    pwm_setup_all();
    adc_start();
    //calibrate();
}
