//-------------------------------------------
/*
PWM.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef PWM_H
#define PWM_H
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void pwm_setup_all(void);

void pwm_setup0(void);

void pwm0A(unsigned int value);
void pwm_ramp0A(unsigned int value, unsigned int speed);
void pwm_rampUp0A(unsigned int value, unsigned int speed);
void pwm_rampDown0A(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value0A;
volatile unsigned int pwm_speed0A;
volatile unsigned int pwm_value_old0A;

void pwm0B(unsigned int value);
void pwm_ramp0B(unsigned int value, unsigned int speed);
void pwm_rampUp0B(unsigned int value, unsigned int speed);
void pwm_rampDown0B(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value0B;
volatile unsigned int pwm_speed0B;
volatile unsigned int pwm_value_old0B;

void pwm_setup1(void);

void pwm1A(int value);
void pwm_ramp1A(int value, int speed);
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

void pwm_setup2(void);

void pwm2A(unsigned int value);
void pwm_ramp2A(unsigned int value, unsigned int speed);
void pwm_rampUp2A(unsigned int value, unsigned int speed);
void pwm_rampDown2A(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value2A;
volatile unsigned int pwm_speed2A;
volatile unsigned int pwm_value_old2A;

void pwm2B(unsigned int value);
void pwm_ramp2B(unsigned int value, unsigned int speed);
void pwm_rampUp2B(unsigned int value, unsigned int speed);
void pwm_rampDown2B(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value2B;
volatile unsigned int pwm_speed2B;
volatile unsigned int pwm_value_old2B;
#endif
