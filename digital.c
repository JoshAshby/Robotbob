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
 /** \brief Turn a pin on PORTB on or off (or in reality, switch it from sourceing to sinking current)
 *
 * \param pin int - Which pin is set to source or sink current
 * \param value _Bool - Whether the pin is sourcing or sinking current
 * \return void Returns nothing
 *
 */
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
 /** \brief Turn a pin on PORTD on or off (or in reality, switch it from sourceing to sinking current)
 *
 * \param pin int - Which pin is set to source or sink current
 * \param value _Bool - Whether the pin is sourcing or sinking current
 * \return void Returns nothing
 *
 */
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
 /** \brief Turn a pin on the given port on or off (or in reality, switch it from sourceing to sinking current)
 *
 * \param port char - Which port is the pin on? (ie: 'B' or 'D')
 * \param pin int - Which pin is set to source or sink current
 * \param value _Bool - Whether the pin is sourcing or sinking current
 * \return void Returns nothing
 *
 */
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

/** \brief Sets up timer0 for the overflow interrupt which is then used for button debouncing
 *
 * \param void
 * \return void
 *
 */
void setup_timer0(void) {
    TCNT0 = 0; //set the inital timer value to 0
    TCCR0B |= (1<<CS01); //set the clock prescaler to clock/8 or 2mHz
    TIMSK0 |= (1<<TOIE0); //start the timer with the interrupt overflow turned on
}

/** \brief Goes through and checks the state of the counter associated with each button to see if the button is stable
 *
 * \param void
 * \return void
 *
 */
void check_buttons(void) {
    /*
    This little bit of code takes care of debouncing the button, with the aid of the
    Timer0 ISR which keeps track of how stable the button is. If the button is stable
    then this bit of code will change it's matching variable which indicates the state
    for the rest of the code. If the button isn't stable then it doesn't do anything.
    */
    //button one
    if (count[0] > 10) { //if the buttons stable, set the array for button 1 as stable
        //and reset the counter if the buttons been released
        /*if ((PIND & button_one) == 0) {
            count[0] = 0;
        }*/
        button[0] = 1;
    }
    if ((PIND & button_one) == 0) {
        button[0] = 0;
    }

    //button one
    if (count[1] > 10) { //if the buttons stable, set the array for button 1 as stable
        //and reset the counter if the buttons been released
        /*if ((PIND & button_one) == 0) {
            count[0] = 0;
        }*/
        button[1] = 1;
    }
    if ((PIND & button_two) == 0) {
        button[1] = 0;
    }
}

/** \brief Button handler code which will run the gived code for each button if it has been pressed
 *
 * \param void
 * \return void
 *
 */
void buttons(void) {
    /*
    This little function holds all of the handlers for the buttons, ie: what to do when
    a button has been pressed.
    */
    if (button[0] == 1) { //If the first button is pulled high then
        /*for (i_one = 0; i_one < 2; i_one++) {
            uart_sendint(ultrasound_filter(1));
        }*/
        do {
            uart_sendint(ultrasound_filter(1));
        } while (i_one == 0);
        i_one++;
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
