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
int rollAverage[20] = {0};
int average = 0;
int i = 0;
int j;
int main(void)
{
    setup();
    pwm_setup2();
    for(;;){
        //simple test, runs through a few different commands
        adc_change(4);
        for (i = 0; i <= 20; i++){
            rollAverage[i] = ADCH;
        }
        for (j = 0; j <= 20; j++){
            average += rollAverage[j];
            average = average/20;
        }
        pwm2B(average);
    }
return 0;   //  never reached
}
