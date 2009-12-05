/*
  Robot.cpp - Library for my robot.
  Created by Josh Ashby, August 7, 2009.
  Released into the public domain(see below).
------------------------------------------------------
12-4-09 .::. Josh Ashby
-added the readTurn, readSpeed, writeTurn, and writeSpeed commands
 :this completes the tie in with the new i2c coms between the 2 microcontrollers
-added a bit of documentation
-now licensed under the Creative Commons v3 Non-commercial License
*/

#include "WProgram.h"
#include "Robot.h"

Robot::Robot(int pin, int pin1, int pin2, int pin3)
{
  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  _pin = pin;   //direction controller
  _pin1 = pin1; //speed controller
  _pin2 = pin2; //turn controller
  _pin3 = pin3; //turn relay
}

Robot::twiAdress(int set1, int set2, int set3, int set4)
{
   pinMode(set1, OUTPUT);
   pinMode(set2, INPUT);
   pinMode(set3, INPUT);
   pinMode(set4, INPUT);
   _set1 = set1;
   _set2 = set2;
   _set3 = set3;
   _set4 = set4;
}

void Robot::setAddress(int master)
{
  if (master == 1) {
     Wire.begin();
  }
  if (master == 0) {
     digitalWrite(_set1, HIGH);
     x = digitalRead(_set2);
     if (x == HIGH) {
        digitalWrite(_set4, HIGH);
        y = digitalRead(_set3);
        if (y == HIGH) {
           Wire.begin(5);
        }
        if (y == LOW) {
           Wire.begin(1);
        }
        digitalWrite(_set4, LOW);
     }
     if (x == LOW) {
        digitalWrite(_set1, LOW);
        digitalWrite(_set4, HIGH);
        x = digitalRead(_set3);
        if (x == HIGH) {
           Wire.begin(2);
        }
        digitalWrite(_set4, LOW);
     }
     x = digitalRead(_set3);
     if (x == HIGH) {
        digitalWrite(_set4, HIGH);
        y = digitalRead(_set2);
        if (y == HIGH) {
           Wire.begin(6);
        }
        if (y == LOW) {
           Wire.begin(3);
        }
        digitalWrite(_set4, LOW);
     }
     if (x == LOW) {
        digitalWrite(_set1, LOW);
        digitalWrite(_set4, HIGH);
        y = digitalRead(_set2);
        if (y == HIGH) {
           Wire.begin(4);
        }
        digitalWrite(_set4, LOW);
     }
  }
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

void Robot::writeTurn(int slot, int direction)
{
  Wire.beginTransmission(slot);
  Wire.send(direction);
  Wire.endTransmission();
}

void Robot::writeSpeed(int slot, int direction, int speed)
{
  Wire.beginTransmission(slot);
  Wire.send(direction);
  Wire.send(speed);
  Wire.endTransmission();
}

void Robot::readTurn()
{
 while (Wire.available()) {
    x = Wire.receive();
    if (x == "left") {
      return "0";
    }
    if (x == "right") {
      return "1";
    }
 }
}


void Robot::readSpeed()
{
 while (Wire.available()) {
    x = Wire.receive();
    if (x == "f") {
      int y = 0
    }
    if (x == "b") {
      int y = 1
    }
    x = Wire.receive();
    return y, x
 }
}
