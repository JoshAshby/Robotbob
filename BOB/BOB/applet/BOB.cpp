#include "WProgram.h"
void setup();
void loop();
int pinArray[4] = {9, 10, 2, 3}; // digital pins for the motors
int i;              // iterator
int motor;          // control pin for current servo
int userInput[4];   // raw input from serial buffer, 3 bytes
int motorspeed;          // commanded speed
int motorf[2];      // motorfront #1 array{pin, pulsewidth}
int motorb[2];      // motorback #2 array{pin, pulsewidth}
int pin;            // digital pin for pulse() function
int puls;           // pulsewidth for pulse() function
int startbyte;      // start byte, begin reading input
int relayf[2];      //front relay
int relayb[2];       //back relay
int motordirection; //which way?
int fb = 0;         //convert the python which way to a value the arduino can use

void setup() {
  // loop through all 4 servo pins
  // and set them as OUTPUT
  for (i=0;i<4;i++) {
    pinMode(pinArray[i], OUTPUT);
  }  
  // map pins to motor controllers
  motorf[0] = pinArray[0];  // front motor is pin 9
  motorb[0] = pinArray[1];  // back motor is pin 10
  relayf[0] = pinArray[2];  //front relay is pin 2
  relayb[0] = pinArray[3];  //back relay is pin 3
  Serial.begin(9600);
  digitalWrite(motorf[0], LOW);//turn all the pins low to make sure the robot doesn't take off
  digitalWrite(motorb[0], LOW);
  digitalWrite(relayf[0], LOW);
  digitalWrite(relayb[0], LOW);
}

void loop() {
  // wait for serial input (min 3 bytes in buffer)
  if (Serial.available() > 3) {
    //read the first byte
    startbyte = Serial.read();
    // if it's really the startbyte (255)
    if (startbyte == 255) {
      // then get the next two bytes
      for (i=0;i<3;i++) {
        userInput[i] = Serial.read();
      }
      // first byte = motor to move?
      motor = userInput[0];
      // second byte = what speed?
      motorspeed = userInput[1];
      //third byte = what direction
      motordirection = userInput[2];
      if (motordirection == 253) {
        fb = LOW; //if the motor direction is 253 then turn off the relay
      }
      if (motordirection == 254) {
        fb = HIGH; //if the motor direction is 254 then turn on the relay
      }
      switch (motor) {
        case 1:
          motorf[1] = motorspeed;
          relayf[1] = fb;
          break;
        case 2:
          motorb[1] = motorspeed;
          relayb[1] = fb;
          break;
      }
    }
    digitalWrite(motorf[0], motorf[1]);//write the speed to the right motor
    digitalWrite(motorb[0], motorb[1]);//write the speed to the right motor
    digitalWrite(relayf[0], relayf[1]);//write the direction to the right relay
    digitalWrite(relayb[0], relayb[1]);//write the direction to the right relay

  }
}


int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

