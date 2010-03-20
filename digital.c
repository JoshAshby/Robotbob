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
#include "digital.h"
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
void inputB(int pin, int value)
{
    if (value == 0)
    {
        DDRB |= (0<<pin);
    }
    else
    {
        DDRB |= (1<<pin);
    }
}
void inputD(int pin, int value)
{
    if (value == 0)
    {
        DDRD |= (0<<pin);
    }
    else
    {
        DDRD |= (1<<pin);
    }
}
void out(char port, int pin, bool value){
    switch (port) {
        case D:
            switch (value) {
                case 0:
                    PORTD &= ~(1<<pin);
                    break;
                case 1:
                    PORTD |= (1<<pin);
                    break;
            }
            break;
        case B:
            switch (value) {
                case 0:
                    PORTB &= ~(1<<pin);
                    break;
                case 1:
                    PORTB |= (1<<pin);
                    break;
            }
            break;
    }
}
