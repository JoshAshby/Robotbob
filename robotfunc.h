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
#include "global.h"

//-------------------------------------------
//Prototypes
//-------------------------------------------

/*uint16_t ultrasound_filter(char pin);
void calibrate(char pin);

//-------------------------------------------
//Variables
//-------------------------------------------

volatile uint8_t rollAverage[30];
volatile uint16_t average;
volatile uint8_t j;
volatile uint16_t adc;*/

volatile uint8_t filt;
volatile uint8_t rollAverage[24];
volatile uint8_t average;
volatile uint8_t j;
volatile uint8_t adc;
uint8_t ultrasound_filter(char pin);

#endif
