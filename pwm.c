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
void pwm_setup(void)
{
    TCCR1B |= (1<<CS11)
            | (1<<CS10);
    TCCR1A |= (1<<WGM10);

    DDRB |= (1<<1);
    DDRB |= (1<<2);

    pwm_speed1A = 0;
    pwm_value1A = 0;
    pwm_value_old1A = 0;

    pwm_speed1B = 0;
    pwm_value1B = 0;
    pwm_value_old1B = 0;
}
void pwm1A(unsigned int value)//set the duty cycle on the PWM
{
    TCCR1A |= (1<<COM1A1);
    OCR1A = value;
}
void pwm1B(unsigned int value)//set the duty cycle on the PWM
{
    TCCR1A |= (1<<COM1B1);
    OCR1B = value;
}
//calling any of these wll stop the processor for a short amonnt of time due to the delay
void pwm_ramp1A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
    pwm1A(0);
    }
    else {
    if (value > pwm_value_old1A){//determine if it should ramp up or down
        TCCR1A |= (1<<COM1A1);
        unsigned int i = pwm_value_old1A;
        while (i<=value) {//ramp up
            OCR1A=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old1A = value;//store the old pwm for autoramping
    } else {
        TCCR1A |= (1<<COM1A1);
        unsigned int i = pwm_value_old1A;
        while (i>=value) {//ramp down
            OCR1A=i;
            i--;
            _delay_ms(speed);
        }
    }
        pwm_value_old1A = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp1A(unsigned int value, unsigned int speed)
{
    TCCR1A |= (1<<COM1A1);
    unsigned int i = pwm_value_old1A;
    while (i<=value) {//ramp up
        OCR1A=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old1A = value;//store the old pwm for autoramping
}
void pwm_rampDown1A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm1A(0);
    }
    else {
    TCCR1A |= (1<<COM1A1);
    unsigned int i = pwm_value_old1A;
    while (i>=value) {//ramp down
        OCR1A=i;
        i--;
        _delay_ms(speed);
    }
    }
    pwm_value_old1A = value;//store the old pwm for autoramping
}


void pwm_ramp1B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
    value = 1;
    }
    if (value > pwm_value_old1B){//determine if it should ramp up or down
        TCCR1A |= (1<<COM1B1);
        unsigned int i = pwm_value_old1B;
        while (i<=value) {//ramp up
            OCR1B=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old1B = value;//store the old pwm for autoramping
    } else {
        TCCR1A |= (1<<COM1B1);
        unsigned int i = pwm_value_old1B;
        while (i>=value) {//ramp down
            OCR1B=i;
            i--;
            _delay_ms(speed);
        }
        pwm_value_old1B = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp1B(unsigned int value, unsigned int speed)
{
    TCCR1A |= (1<<COM1B1);
    unsigned int i = pwm_value_old1B;
    while (i<=value) {//ramp up
        OCR1B=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old1B = value;//store the old pwm for autoramping
}
void pwm_rampDown1B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
    value = 1;
    }
    TCCR1A |= (1<<COM1B1);
    unsigned int i = pwm_value_old1B;
    while (i>=value) {//ramp down
        OCR1B=i;
        i--;
        _delay_ms(speed);
    }
    pwm_value_old1B = value;//store the old pwm for autoramping
}
