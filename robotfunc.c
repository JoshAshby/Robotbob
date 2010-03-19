#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include <avr/delay.h>
#include "boot.h"
#include "robotfunc.h"
//-------------------------------------------
/*
robotfunc.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
void turn_left(){
    /*this will look to each ultrasound, and make sure the robot is good to turn left
    E.G: if the robot is less than 10ft on average then the robot will not turn
    However, this will be a setting incase the robot only has the building on the left of it*/
    if (dirrection == 1) {
    /*read the front diagonal ultrasound, if it's clear, switch to the side ultrasound, it it is clear
    or has a sudden jump, turn */
    }

}
void turn_right(){
    /*this will look to each ultrasound, and make sure the robot is good to turn right
    E.G: if the robot is less than 10ft on average then the robot will not turn
    However, this will be a setting incase the robot only has the building on the right of it*/
    if (dirrection == 0) {
    /*read the front diagonal ultrasound, if it's clear, switch to the side ultrasound, it it is clear
    or has a sudden jump, turn */
    }
}
void stop(){
    //stops everything and sets the STATUS LED to error
    error();
}
