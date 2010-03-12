#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include <avr/delay.h>
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
    adc_start();//because we're using interrupts ADCH will auto update'
    DDRD |= (1<<2);//LED 1
    DDRD |= (1<<3);//LED2
    DDRD |= (1<<4);//relay 1
    DDRD |= (1<<5);//relay 2
    portD_out(2, 1);//says that power is on and the uC is running
    pwm_ramp1A(255, 20);
    for(;;){
        portD_out(3,1);//show that the PWM ramp up was good, this is mainly a debuging thing as i doubt i will be able to see the LED on when BOB's driving in the AVC '10
    }
return 0;   //  never reached
}
