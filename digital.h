//-------------------------------------------
/*
DIGITAL.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef DIGITAL_H
#define DIGITAL_H
#include <avr/io.h>
void portB_out(int pin, int value);
void portD_out(int pin, int value);
void out(char port, int pin, int value);
#endif
