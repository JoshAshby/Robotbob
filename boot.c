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

/* Coming soon: error reporting
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
*/

void bios(void) {
    DDRD |= (1<<CPU_POW); //CPU power led to output, and turn it on
    PORTD |= (1<<CPU_POW);

    DDRD |= (1<<stat_led1);//stat led one
    DDRD |= (1<<stat_led2);//stat led two
    DDRD |= (1<<turn_relay);//turn relay pin to output
    DDRD |= (1<<drive_relay);//drive relay pin to output

    pwm_setup_all(); //start all the pwm channels
    adc_start(1); //start the adc converters
    uart_start(); //start the UART interface
    twi_start(); //start the TWI/I2C interface
    setup_timer0();

    DDRD |= (0<<3)
         |  (0<<4); //setup the button pins as inputs
}
