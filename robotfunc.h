//-------------------------------------------
/*
robotfunc.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#ifndef ROBOTFUNC_H
#define ROBOTFUNC_H
#include <avr/io.h>

volatile int rollAverage[20];
volatile int average;
volatile int j;
volatile int adc;

char can_turn_left(void);
char can_turn_right(void);
void turn_left(void);
void turn_right(void);
void stop(void);
int ultrasound_filter(int pin);
void calibrate(void);
void ultrasound_test(void);

#endif
