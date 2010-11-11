//-------------------------------------------
/*
ADC.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef ADC_H
#define ADC_H
#include <avr/io.h>
#include <avr/interrupt.h>
void adc_start(void);
void adc_stop(void);
void adc_change(int chan);
#endif
