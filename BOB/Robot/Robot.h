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
    twiAdress(int set1, int set2, int set3, int set4);
    void setAddress(int master);
    void backward(int speed);
    void forward(int speed);
    void stop();
    void left();
    void right();
    void writeTurn(int slot, int direction);
    void writeSpeed(int slot, int direction, int speed);
    void readTurn();
    void readSpeed();
  private:
    int _pin;
    int _pin1;
    int _pin2;
    int _pin3;
    int _set1;
    int _set2;
    int _set3;
    int _set4;
};

#endif
