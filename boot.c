#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include <avr/delay.h>

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
    out('D', 3, 1);
}
void oh_crap(){//status led off
    out('D', 3, 0);
}
void error(int type){//blink the status led if there is an error
    switch (type) {
        case 0:
            out('D', 3, 1);
            _delay_ms(500);
            out('D', 3, 0);
            _delay_ms(500);
            break;
        case 1:
            pwm_ramp2B(255, 10);
            pwm_ramp2B(1, 10);
            break;
    }
}
void setup(){
    DDRD |= (1<<2);//LED power
    DDRD |= (1<<3);//LED Status
    DDRD |= (1<<4);//relay back
    DDRD |= (1<<5);//relay front
    out('D', 2, 1);//CPU power LED
    pwm_setup_all();
    calibrate();
    adc_start();//because we're using interrupts ADCH will auto update'
    all_good();
}
void test(){
    pwm_ramp1A(255, 10);
    _delay_ms(500);
    pwm_ramp1A(0, 10);
    out('D', 4, 1);
    pwm_ramp1A(255, 10);
    _delay_ms(500);
    pwm_ramp1A(0,10);
    out('D', 4, 0);
    oh_crap();
    _delay_ms(1000);
    all_good();
    pwm1B(255);
    _delay_ms(500);
    pwm1B(0);
    out('D', 5, 1);
    _delay_ms(500);
    pwm1B(255);
    _delay_ms(500);
    pwm1B(0);
    out('D', 5, 0);
}
