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

int pwm_setup(void);
int pwm(unsigned int value, unsigned int speed);
int pwm_ramp(unsigned int value, unsigned int speed);
int pwm_rampUp(unsigned int value, unsigned int speed);
int pwm_rampDown(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value;
volatile unsigned int pwm_speed;
volatile unsigned int pwm_value_old;
#endif
