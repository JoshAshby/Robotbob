//-------------------------------------------
/*
main.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

int main(void) { //Main loop, runs once but can have an infinit loop in it
    DDRD |= (1<<CPU_POW);
    PORTD |= (1<<CPU_POW);

    //various start up parts, these run once since they are not with in the main
    //while loop that runs forever. (see below)
    pwm_setup_all(); //start all the pwm channels
    adc_start(1); //start the adc converters
    uart_start(); //start the UART interface
    twi_start(); //start the TWI/I2C interface

    DDRD |= (0<<3)
         |  (0<<4); //setup the button pins as inputs

    init_button_timer0(); //start the timer that takes care of the interrupt which
    //holds the counter for button debouncing

    while(1) { //infinit loop that doesn't stop running. (always true since 1 is always 1
        check_buttons(); //debounces the buttons with the aid of the timer0 interrupt
        buttons(); //if a buttons been pressed, code inside of here will run, if not
        //it's skiped over. simply cleans up this part of the code
    };
    return 0; //never reached since 1 is always true
}
