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

#define Stat1 3 //which pin is the stat LED on?
#define statPower 2 //which pin is the CPU power on?
//#define stat2

#define Button1 2

//#define button1
//#define button2

#define Trelay 4 //which pin is the Front turning motor relay on?
#define Drelay 5 //which pin is the back propulsion motor relay on?

#define Tmotor 2 //which pin is the front turning motor on?
//#define Dmotor //not really used, here just incase. typically this pin is addressed via this pwm1a channel and commands

int base;

#endif

