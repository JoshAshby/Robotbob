/*
  Robot.h a library for my robot
  Created by Josh Ashby, August 7, 2009.
  Released into the public domain.
*/
#ifndef Robot_h
#define Robot_h

#include "WProgram.h"

class Robot
{
  public:
    Robot(int pin, int pin1, int pin2, int pin3);
    void backward(int speed);
    void forward(int speed);
    void stop();
    void left();
    void right();
  private:
    int _pin;
    int _pin1;
    int _pin2;
    int _pin3;
};

#endif
