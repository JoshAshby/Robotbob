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
#ifndef PWM_H
#define PWM_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

int pwm_setup(void);
int pwm(unsigned int value, unsigned int speed);
int pwm_ramp(unsigned int value, unsigned int speed);
volatile unsigned int pwm_value;
volatile unsigned int pwm_speed;
volatile unsigned int pwm_value_old;
volatile unsigned int i;
#endif
