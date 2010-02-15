//-------------------------------------------
/*
PWM.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#include "pwm.h"
int pwm_setup(void)
{
    TCCR1B |= (1<<CS11)
            | (1<<CS10);
    TCCR1A |= (1<<WGM10);
    DDRB |= (1<<1);
    DDRB |= (1<<2);
    pwm_speed = 0;
    pwm_value = 0;
    pwm_value_old = 0;
    return 1;
}
int pwm(unsigned int value, unsigned int speed)
{
    TCCR1A |= (1<<COM1A1);
    OCR1A = value;
    return 1;
}
int pwm_ramp(unsigned int value, unsigned int speed)
{
    if (value < pwm_value_old){
        TCCR1A |= (1<<COM1A1);
        unsigned int i = pwm_value_old;
        while (i<=value) {
            OCR1A=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old = value;
    } else {
        TCCR1A |= (1<<COM1A1);
        unsigned int i = pwm_value_old;
        while (i>=value) {
            OCR1A=i;
            i--;
            _delay_ms(speed);
        }
        pwm_value_old = value;
    }
    return 1;
}
int pwm_rampUp(unsigned int value, unsigned int speed)
{
    TCCR1A |= (1<<COM1A1);
    unsigned int i = pwm_value_old;
    while (i<=value) {
        OCR1A=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old = value;
    return 1;
}
int pwm_rampDown(unsigned int value, unsigned int speed)
{
    TCCR1A |= (1<<COM1A1);
    unsigned int i = pwm_value_old;
    while (i>=value) {
        OCR1A=i;
        i--;
        _delay_ms(speed);
    }
    pwm_value_old = value;
    return 1;
}
