/*
  Robot.cpp - Library for my robot.
  Created by Josh Ashby, August 7, 2009.
  Released into the public domain.
*/

#include "WProgram.h"
#include "Robot.h"

Robot::Robot(int pin, int pin1, int pin2, int pin3)
{
  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  _pin = pin;
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
}

void Robot::backward(int speed)
{
  digitalWrite(_pin1, HIGH);
  analogWrite(_pin, speed);
}

void Robot::forward(int speed)
{
  analogWrite(_pin, speed);
}

void Robot::stop()
{
  digitalWrite(_pin, LOW);
  digitalWrite(_pin1, LOW);
}

void Robot::left()
{
  digitalWrite(_pin2, HIGH);
  delay(200);
  digitalWrite(_pin2, LOW);
}

void Robot::right()
{
  digitalWrite(_pin3, HIGH);
  digitalWrite(_pin2, HIGH);
  delay(200);
  digitalWrite(_pin2, LOW);
  digitalWrite(_pin3, LOW);
}