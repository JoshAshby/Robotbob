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
#include "global.h"

//-------------------------------------------
//Prototypes
//-------------------------------------------

void portB_out(int pin, _Bool value);
void portD_out(int pin, _Bool value);
void out(char port, int pin, _Bool value);
void setup_timer0(void);
void buttons(void);
void check_buttons(void);
void run_once(void);

//-------------------------------------------
//Variables
//-------------------------------------------

uint8_t i_one;

#endif
