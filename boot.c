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
#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
#include <util/delay.h>
//add a basic bios that will take, start the ADC, calibrate the sensors to what value they should try to stay at
//also go through and make sure everything is working from what it can tell if there is an error then it will blink the status led
void all_good(){//turn the status led on
    out('D', Stat1, 1);
}
void oh_crap(){//status led off
    out('D', Stat1, 0);
}
void error(int type){//blink the status led if there is an error
    switch (type) {
        case 0:
            out('D', Stat1, 1);
            _delay_ms(500);
            out('D', Stat1, 0);
            _delay_ms(500);
            break;
        case 1:
            pwm_ramp2B(255, 10);
            pwm_ramp2B(1, 10);
            break;
        case 2:
            pwm_ramp2B(255, 50);
            pwm_ramp2B(0, 10);
            break;
    }
}
void bios(){
    DDRD |= (1<<statPower);//LED power
    DDRD |= (1<<Stat1);//LED Status
    DDRD |= (1<<Trelay);//relay back
    DDRD |= (1<<Drelay);//relay front
    out('D', statPower, 1);//CPU power LED
    pwm_setup_all();
    adc_start();//because we're using interrupts ADCH will auto update
    calibrate();
    all_good();
}
