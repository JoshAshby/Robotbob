//-------------------------------------------
/*
robotfunc.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef ROBOTFUNC_H
#define ROBOTFUNC_H
#include global.h

//-------------------------------------------
//Prototypes
//-------------------------------------------

int ultrasound_filter(int pin);
void calibrate(void);

//-------------------------------------------
//Variables
//-------------------------------------------

volatile int rollAverage[30];
volatile int average;
volatile int j;
volatile int adc;

#endif
