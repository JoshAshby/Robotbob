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

//-----------------------------------------------
//Libraries
//-----------------------------------------------

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <compat/twi.h>
#include <inttypes.h>
#include <stdlib.h>
#include <avr/sleep.h>

#include "adc.h"
#include "pwm.h"
#include "i2c.h"
#include "uart.h"
#include "digital.h"
#include "boot.h"
#include "robotfunc.h"

//-----------------------------------------------
//Defines
//-----------------------------------------------

#define debug 1 //if true, anything inside of an if(debug){} tag will run

#define MCP_ADDRESS 0xC0 //address of the MCP I2C DAC

//Buttons
#define button_one 0b00001000 //PORTD pin 3
#define button_two 0b00010000 //PORTD pin 4

//Status LEDs
#define stat_led1 5 //PORTD
#define stat_led2 6 //PORTD

//CPU power LED
//On my Dev board this pin bootstraps the regulator so the power button can be released
//On BOB this is the LED which lets you know the CPU is alive
#define CPU_POW 2 //PORTD

//addresses of the IGT I2C gyroscope
#define	GX_H	0x1D
#define	GX_L	0x1E
#define	GY_H	0x1F
#define	GY_L	0x20
#define GZ_H	0x21
#define GZ_L	0x22

//relays
#define turn_relay 2
#define drive_relay 3

//-----------------------------------------------
//Variables
//-----------------------------------------------

uint8_t count[2];
unsigned char button[2];
uint16_t base;

#endif
