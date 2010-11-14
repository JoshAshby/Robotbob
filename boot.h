//-------------------------------------------
/*
boot.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef BOOT_H
#define BOOT_H
#include <avr/io.h>
#include <util/delay.h>
//prototypes
void bios(void);
void all_good(void);
void oh_crap(void);
void error(int type);
#endif
