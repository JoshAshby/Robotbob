//-------------------------------------------
/*
PWM.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
/*
Information about this file and all the registers used in it
can be found on page 251 section 23 of the Atmega datasheet
*/
//-------------------------------------------
#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
void pwm_setup_all(void){
    TCCR0B |= (1<<CS00)
            | (1<<CS01);
    TCCR0A |= (1<<WGM00);

    DDRD |= (1<<5);
    DDRD |= (1<<6);

    pwm_speed0A = 0;
    pwm_value0A = 0;
    pwm_value_old0A = 0;

    pwm_speed0B = 0;
    pwm_value0B = 0;
    pwm_value_old0B = 0;

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

    TCCR2B |= (1<<CS22);
    TCCR2A |= (1<<WGM20);

    DDRD |= (1<<3);
    DDRB |= (1<<3);

    pwm_speed2A = 0;
    pwm_value2A = 0;
    pwm_value_old2A = 0;

    pwm_speed2B = 0;
    pwm_value2B = 0;
    pwm_value_old2B = 0;
}
void pwm_setup0(void)
{
    TCCR0B |= (1<<CS00)
            | (1<<CS01);
    TCCR0A |= (1<<WGM00);

    DDRD |= (1<<5);
    DDRD |= (1<<6);

    pwm_speed0A = 0;
    pwm_value0A = 0;
    pwm_value_old0A = 0;

    pwm_speed0B = 0;
    pwm_value0B = 0;
    pwm_value_old0B = 0;
}
void pwm0A(unsigned int value)//set the duty cycle on the PWM
{
    TCCR0A |= (1<<COM0A1);
    OCR0A = value;
}
void pwm0B(unsigned int value)//set the duty cycle on the PWM
{
    TCCR0A |= (1<<COM0B1);
    OCR0B = value;
}
//calling any of these wll stop the processor for a short amonnt of time due to the delay
void pwm_ramp0A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm0A(0);
    }
    else {
    if (value > pwm_value_old1A){//determine if it should ramp up or down
        TCCR0A |= (1<<COM0A1);
        unsigned int i = pwm_value_old0A;
        while (i<=value) {//ramp up
            OCR0A=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old0A = value;//store the old pwm for autoramping
    } else {
        TCCR0A |= (1<<COM0A1);
        unsigned int i = pwm_value_old0A;
        while (i>=value) {//ramp down
            OCR0A=i;
            i--;
            _delay_ms(speed);
        }
    }
        pwm_value_old0A = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp0A(unsigned int value, unsigned int speed)
{
    TCCR0A |= (1<<COM0A1);
    unsigned int i = pwm_value_old0A;
    while (i<=value) {//ramp up
        OCR0A=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old0A = value;//store the old pwm for autoramping
}
void pwm_rampDown0A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm0A(0);
    }
    else {
    TCCR0A |= (1<<COM0A1);
    unsigned int i = pwm_value_old0A;
    while (i>=value) {//ramp down
        OCR0A=i;
        i--;
        _delay_ms(speed);
    }
    }
    pwm_value_old0A = value;//store the old pwm for autoramping
}


void pwm_ramp0B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm0B(0);
    }
    if (value > pwm_value_old0B){//determine if it should ramp up or down
        TCCR0A |= (1<<COM0B1);
        unsigned int i = pwm_value_old0B;
        while (i<=value) {//ramp up
            OCR0B=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old0B = value;//store the old pwm for autoramping
    } else {
        TCCR0A |= (1<<COM0B1);
        unsigned int i = pwm_value_old0B;
        while (i>=value) {//ramp down
            OCR0B=i;
            i--;
            _delay_ms(speed);
        }
        pwm_value_old0B = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp0B(unsigned int value, unsigned int speed)
{
    TCCR0A |= (1<<COM0B1);
    unsigned int i = pwm_value_old0B;
    while (i<=value) {//ramp up
        OCR0B=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old0B = value;//store the old pwm for autoramping
}
void pwm_rampDown0B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm0B(0);
    }
    TCCR0A |= (1<<COM0B1);
    unsigned int i = pwm_value_old0B;
    while (i>=value) {//ramp down
        OCR1B=i;
        i--;
        _delay_ms(speed);
    }
    pwm_value_old0B = value;//store the old pwm for autoramping
}

//-------------------------------------------
void pwm_setup1(void)
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
void pwm1A(int value)//set the duty cycle on the PWM
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
void pwm_ramp1A(int value, int speed)
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
        pwm1B(0);
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
        pwm1B(0);
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
//--------------------------------------------
void pwm_setup2(void)
{
    TCCR2B |= (1<<CS22);
    TCCR2A |= (1<<WGM20);

    DDRD |= (1<<3);
    DDRB |= (1<<3);

    pwm_speed2A = 0;
    pwm_value2A = 0;
    pwm_value_old2A = 0;

    pwm_speed2B = 0;
    pwm_value2B = 0;
    pwm_value_old2B = 0;
}
void pwm2A(unsigned int value)//set the duty cycle on the PWM
{
    TCCR2A |= (1<<COM2A1);
    OCR2A = value;
}
void pwm2B(unsigned int value)//set the duty cycle on the PWM
{
    TCCR2A |= (1<<COM2B1);
    OCR2B = value;
}
//calling any of these wll stop the processor for a short amonnt of time due to the delay
void pwm_ramp2A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm2A(0);
    }
    else {
    if (value > pwm_value_old2A){//determine if it should ramp up or down
        TCCR2A |= (1<<COM2A1);
        unsigned int i = pwm_value_old2A;
        while (i<=value) {//ramp up
            OCR2A=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old2A = value;//store the old pwm for autoramping
    } else {
        TCCR2A |= (1<<COM2A1);
        unsigned int i = pwm_value_old2A;
        while (i>=value) {//ramp down
            OCR2A=i;
            i--;
            _delay_ms(speed);
        }
    }
        pwm_value_old2A = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp2A(unsigned int value, unsigned int speed)
{
    TCCR2A |= (1<<COM2A1);
    unsigned int i = pwm_value_old2A;
    while (i<=value) {//ramp up
        OCR2A=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old2A = value;//store the old pwm for autoramping
}
void pwm_rampDown2A(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm2A(0);
    }
    else {
    TCCR2A |= (1<<COM2A1);
    unsigned int i = pwm_value_old2A;
    while (i>=value) {//ramp down
        OCR2A=i;
        i--;
        _delay_ms(speed);
    }
    }
    pwm_value_old2A = value;//store the old pwm for autoramping
}


void pwm_ramp2B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm2B(0);
    }
    if (value > pwm_value_old2B){//determine if it should ramp up or down
        TCCR2A |= (1<<COM2B1);
        unsigned int i = pwm_value_old2B;
        while (i<=value) {//ramp up
            OCR2B=i;
            i++;
            _delay_ms(speed);
        }
        pwm_value_old2B = value;//store the old pwm for autoramping
    } else {
        TCCR2A |= (1<<COM2B1);
        unsigned int i = pwm_value_old2B;
        while (i>=value) {//ramp down
            OCR2B=i;
            i--;
            _delay_ms(speed);
        }
        pwm_value_old2B = value;//store the old pwm for autoramping
    }
}
void pwm_rampUp2B(unsigned int value, unsigned int speed)
{
    TCCR2A |= (1<<COM2B1);
    unsigned int i = pwm_value_old2B;
    while (i<=value) {//ramp up
        OCR2B=i;
        i++;
        _delay_ms(speed);
    }
    pwm_value_old2B = value;//store the old pwm for autoramping
}
void pwm_rampDown2B(unsigned int value, unsigned int speed)
{
    if (value == 0) {//safe gaurd to prevent i from over flowing
        pwm2B(0);
    }
    TCCR2A |= (1<<COM2B1);
    unsigned int i = pwm_value_old2B;
    while (i>=value) {//ramp down
        OCR2B=i;
        i--;
        _delay_ms(speed);
    }
    pwm_value_old2B = value;//store the old pwm for autoramping
}
