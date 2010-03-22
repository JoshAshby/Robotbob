//-------------------------------------------
/*
boot.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#ifndef BOOT_H
#define BOOT_H
#include <avr/io.h>
#include <util/delay.h>
void bios(void);
void all_good(void);
void oh_crap(void);
void error(int type);
#endif
