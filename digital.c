//-------------------------------------------
/*
DIGITAL.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
//add the ability for it to auto detect which port based on what pin number you give
void portB_out(int pin, int value)
{
    if (value == 0)
    {
        PORTB &= ~(1<<pin);
    }
    else
    {
        PORTB |= (1<<pin);
    }
}
void portD_out(int pin, int value)
{
    if (value == 0)
    {
        PORTD &= ~(1<<pin);
    }
    else
    {
        PORTD |= (1<<pin);
    }
}
void out(char port, int pin, int value){
    switch (port) {
        case 'D':
            if(value == 1){
                PORTD |= (1<<pin);
            }
            else {
                PORTD &= ~(1<<pin);
            }
            break;
        case 'B':
            if(value == 1){
                PORTB |= (1<<pin);
            }
            else {
                PORTB &= ~(1<<pin);
            }
            break;
    }
}
