//-------------------------------------------
/*
PWM function
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#include "pwm.h"
//some of this is a little bit of a hack from arduino's wire_analog.c :D
int pwm_setup(void)
{
    sbi(TCCR1B, CS11);
    sbi(TCCR1B, CS10);
    sbi(TCCR1A, WGM10);
    DDRB |= (1<<1);
    DDRB |= (1<<2);
    return 1;
}
int pwm(unsigned int value, unsigned int speed)
{
    sbi(TCCR1A, COM1A1);
    OCR1A = value;
    return 1;
}
int pwm_ramp(unsigned int value, unsigned int speed)
{
    sbi(TCCR1A, COM1A1);
    unsigned int i;
    if (i == value){
        OCR1A = value;
    } else {
        i++;
        OCR1A = i;
    }
    return 1;
}
