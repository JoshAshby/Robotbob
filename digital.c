//-------------------------------------------
/*
digital.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

void portB_out(int pin, _Bool value) {
    /*
    Change the state of a pin on PORTB
    simply pass the pin number, and either a 0 to sink current or 1 to source it
    */
    if (value == 0) {
        PORTB &= ~(1<<pin);
    } else  {
        PORTB |= (1<<pin);
    }
}

void portD_out(int pin, _Bool value) {
    /*
    Change the state of a pin on PORTD
    simply pass the pin number, and either a 0 to sink current or 1 to source it
    */
    if (value == 0) {
        PORTD &= ~(1<<pin);
    } else {
        PORTD |= (1<<pin);
    }
}

void out(char port, int pin, _Bool value) {
    /*
    Change the state of a pin on given port
    simply pass the Port as either D or B (make sure to enclose it in single
    quotes like so: 'D')
    The pin number you would like to change state of,
    and either a 0 to sink current or 1 to source it on that pin
    */
    switch (port) { //switch determines if which port it is
        case 'D':
            DDRD |= (1<<pin); //change the pin to output
            if(value == 1) { //sink or source current
                PORTD |= (1<<pin);
            } else {
                PORTD &= ~(1<<pin);
            }
            break;
        case 'B':
            DDRB |= (1<<pin); //change pin to output
            if(value == 1) { //sink or source current
                PORTB |= (1<<pin);
            } else {
                PORTB &= ~(1<<pin);
            }
            break;
    }
}

void init_button_timer0(void) {
    TCNT0 = 0; //set the inital timer value to 0
    TCCR0B |= (1<<CS01); //set the clock prescaler to clock/8 or 2mHz
    TIMSK0 |= (1<<TOIE0); //start the timer with the interrupt overflow turned on
}

void check_buttons(void) {
    /*
    This little bit of code takes care of debouncing the button, with the aid of the
    Timer0 ISR which keeps track of how stable the button is. If the button is stable
    then this bit of code will change it's matching variable which indicates the state
    for the rest of the code. If the button isn't stable then it doesn't do anything.
    */
    //button one
    if (count[0] > 5) { //if the buttons stable, set the array for button 1 as stable
        //and reset the counter if the buttons been released
        if ((PIND & button_one) == 0) {
            count[0] = 0;
        }
        button[0] = 1;
    }
    if (count[0] > 250) {
        if ((PIND & button_one) == 0) {
            count[0] = 0;
        }
        button[0] = 2;
    }
    if ((PIND & button_one) == 0) { //reset the counter as soon as button one is released
            button[0] = 0;
    }

    //button two
    if (count[1] > 5) {//if the buttons stable, set the array for button 2 as stable
        //and reset the counter if the buttons been released
        if ((PIND & button_two) == 0) {
            count[1] = 0;
        }
        button[1] = 1;
    }
    if (count[1] > 250) {
        if ((PIND & button_two) == 0) {
            count[1] = 0;
        }
        button[1] = 2;
    }
    if ((PIND & button_two) == 0) {//reset the counter as soon as button two is released
            button[1] = 0;
    }
}

void buttons(void) {
    /*
    This little function holds all of the handlers for the buttons, ie: what to do when
    a button has been pressed.
    */
    if (button[0] == 1) { //If the first button is pulled high then
        //turn pin 1 on port B on
        //out('D',stat_led1,!debug);
        run_once();
    } else { //if either are off, turn pin1 port B off
        out('D',stat_led1,debug);
    }
    if (button[1] == 1) { //If the second button is pulled high then
        //turn pin 2 on port B on
        out('D',stat_led2,!debug);
    } else { //if either are off, turn pin1 port B off
        out('D',stat_led2,debug);
    }
}

void run_once(void) {
    if (count[0]) {
        for(i_one = 0; i_one < 2; i_one++) {
            uart_sendint(88);
        }
    } else {
        i_one = 0;
    }
}

ISR(TIMER0_OVF_vect) {
    /*
    Timer0 overflow interrupt servic routine. Whats in here is a very fancy little
    for each button which will increase if the button is stable in it's state,
    everytime this is ran, or will reset the timer if the button isn't stable, ie
    bouncing, which is what we don't want.
    */
    //figure out what pins been changed, and take the correct action
    if ((PIND & button_one)) {
        //simply increases or resets a counter, the main code then looks at the counter
        //and determines if the buttons been pressed, or held down
        count[0]++; //if buttton_ones been pressed, increase the count, as long as
        //the button continues to stay the same
    } else {
        count[0] = 0;
        //if the button changes state, reset the count
    }
    if ((PIND & button_two)) {
        //simply increases or resets a counter, the main code then looks at the counter
        //and determines if the buttons been pressed, or held down
        count[1]++; //if buttton_ones been pressed, increase the count, as long as
        //the button continues to stay the same
    } else {
        count[1] = 0;
        //if the button changes state, reset the count
    }
}
