//-------------------------------------------
/*
global.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef GLOBAL_H
#define GLOBAL_H

#include <avr/io.h>
#include <util/delay.h>

//variables and other things used through out the libraries.
#define dirrection 0 //which way are you going around the building?
#define debug 1 //are we debuging or not, if this is 1 then debug tests will run and report back via serial and the LEDs

#define Stat1 3
#define statPower 2

#define Trelay 4
#define Drelay 5

#define Tmotor 2
//#define Dmotor

int base;

#endif

