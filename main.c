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
    for(;;){
        //simple test, runs through a few different commands
        test();
    }
return 0;   //  never reached
}
