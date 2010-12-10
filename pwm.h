//-------------------------------------------
/*
PWM.h
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#ifndef PWM_H
#define PWM_H
#include "global.h"

//-------------------------------------------
//Prototypes
//-------------------------------------------

void pwm_setup_all(void);

void pwm_setup0(void);
void pwm0A(uint8_t value);
void pwm0B(uint8_t value);

void pwm_setup1(void);
void pwm1A(uint16_t value);
void pwm1B(uint16_t value);

void pwm_setup2(void);
void pwm2A(uint8_t value);
void pwm2B(uint8_t value);

#endif
