//-------------------------------------------
/*
PWM.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#ifndef PWM_H
#define PWM_H
#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>

void pwm_setup(void);

void pwm1A(unsigned int value);
void pwm_ramp1A(unsigned int value, unsigned int speed);
void pwm_rampUp1A(unsigned int value, unsigned int speed);
void pwm_rampDown1A(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value1A;
volatile unsigned int pwm_speed1A;
volatile unsigned int pwm_value_old1A;

void pwm1B(unsigned int value);
void pwm_ramp1B(unsigned int value, unsigned int speed);
void pwm_rampUp1B(unsigned int value, unsigned int speed);
void pwm_rampDown1B(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value1B;
volatile unsigned int pwm_speed1B;
volatile unsigned int pwm_value_old1B;
#endif
