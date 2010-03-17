#include "adc.h"
#include "pwm.h"
#include "digital.h"
//-------------------------------------------
/*
Boot.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
//add a basica bios that will take, start the ADC, calibrate the sensors to what value they should try to stay at
//also go through and make sure everything is working from what it can tell if there is an error then it will blink the status led
void all_good(){//turn the status led on
    portD_out(3, 1);
}
void oh_crap(){//status led off
    portD_out(3, 0);
}
void error(){//blink the status led if there is an error
    portD_out(3, 1);
    _delay_ms(500);
    portD_out(3, 1);
    _delay_ms(500);
}
void setup(){
    DDRD |= (1<<2);//LED 1
    DDRD |= (1<<3);//LED 2
    DDRD |= (1<<4);//relay 1
    DDRD |= (1<<5);//relay 2
    portD_out(2,1); //say that power is good and the chip is up and running
    pwm_setup();
    adc_start();//because we're using interrupts ADCH will auto update'
    all_good();
}
