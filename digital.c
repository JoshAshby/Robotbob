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
