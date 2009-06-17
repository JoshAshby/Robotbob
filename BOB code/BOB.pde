/*BOB teleoperated code for use with matching python computer side stack
Copywrite 2009 Joshua Ashby
http://joshashby.com
joshuaashby at joshashby.com (joshuaashby@joshashby.com)
TODO:
make the debugs have a "2" option, 0 will not debug, 1 will do serial/usb debuging, and 2 will do led debuging
add suport for changing the debug mode from serial/usb as the code is running
add some words to help with debuging and id of the debug data
add current sensing and voltage sensing for the battery and(?possibly?) have a led bargraph for each
add a temperature led/led bargraph
*/
#define debug 0 //set this to 1 if you want the program to send all debug data through the usb line
#define usbdebug 0 //set this to 1 if you want to debug the usb
#define sensordebug 0 //set this to 1 if you want to debug the raw data the atmega is reading from all sensors
#define motordebug 0 //set this to 1 if you want to debug the raw data from the temperature sensor on the motor controller heatsink
#define error 13 //this is the pin of the error led, if the program recieves an error, then this led will turn on and off
#define usb 5//this is the pin of the usb data led, if there is no usb data coming into the chip, it will fade on and off till it gets data, when it gets data it will light up for every byte
#define relay1 3 //the motor controller relay pin
#define sonarl 1 //the left ultrasound sensor
#define sonarr 2 //the right ultrasound sensor
#define sonarf 3 //the front ultrasound sensor
#define temp1 0 //the motor controller heatsink temperature sensor
int pinArray[5] = {2, 9, 10, 7, 4};
int i;              // iterator
int t = 0;
int servoPosition;
int servoPin;       // control pin for current servo
int userInput[3];   // raw input from serial buffer, 3 bytes
int servo;          // which servo to pulse? 1-4
int servo1[2];      // servo #1 array{pin, pulsewidth}
int servo2[2];      // servo #2 array{pin, pulsewidth}
int servo3[2];      // servo #3 array{pin, pulsewidth}
int servo4[2];      // servo #4 array{pin, pulsewidth}
int startbyte;      // start byte, begin reading input
int distl;
int distr;
int distf;
int temp;

void setup() {
  for (i=0;i<5;i++) {
    pinMode(pinArray[i], OUTPUT);
  }
  servo1[0] = pinArray[0];  // servo #1 is pin 2
  servo2[0] = pinArray[1];  // servo #2 is pin 3
  servo3[0] = pinArray[2];  // servo #3 is pin 4
  servo4[0] = pinArray[3];  // servo #4 is pin 5
  Serial.begin(9600);
  pinMode(usb, OUTPUT);
  pinMode(sonarl, OUTPUT);
  pinMode(sonarr, OUTPUT);
  pinMode(sonarf, OUTPUT);
}

void loop() {
  if (Serial.available() == 0) { /*fade the usb led on and off*/ 
  for (t = 0; t <= 255; t+=5)
  { 
    analogWrite(usb, t);
    delay(30);
  } 
  digitalWrite(usb, LOW);
  delay(30);
  }
  if (Serial.available() > 2) {
    startbyte = Serial.read();
    if (startbyte == 255) {
      if (usbdebug == 1) { //if the debug for usb is set to 1, turn the led on and off for every byte of data that is sent to the atmega
      digitalWrite(usb, HIGH);
      delay(10);
      digitalWrite(usb, LOW);
      }
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      servo = userInput[0];
      servoPosition = userInput[1];
      if (motordebug == 1) { //iof the debug for motors is 1, then the atmega will send the raw data that it is recieving from the computer back, and the data from the temperature sensor on the heatsinks
        Serial.println("motor values:");
        delay(500);
        Serial.println(servoPosition);
        delay(500);
        temp = analogRead(temp1);
        Serial.println("temp:");
        delay(500);
        Serial.println(temp);
        delay(500);
      }
      switch (servo) {
        case 1:
          servo1[1] = servoPosition;
          break;
        case 2:
          servo2[1] = servoPosition;
          break;
        case 3:
          servo3[1] = servoPosition;
          break;
        case 4:
          servo4[1] = servoPosition;
          break;
      }
    }
  }
  analogWrite(servo3[0], servo2[1]);
  if (servo2[1] == 99)
  {
     analogWrite(relay1, 1024);
  }
  else if (servo1[1] != 99)
  {
    analogWrite(relay1, 0);
  }
  while (Serial.available() >= 1) if (sensordebug == 1) { //this will transmit the ultrasound data to the computer if serial data is available and if the debug for sensors is set to 1
    distl = analogRead(sonarl);
    distr = analogRead(sonarr);
    distf = analogRead(sonarf);
    Serial.println("left:");
    delay(500);
    Serial.println(distl);
    delay(500);
    Serial.println("right:");
    delay(500);
    Serial.println(distr);
    delay(500);
    Serial.println("front:");
    delay(500);
    Serial.println(distf);
    delay(500);
  }
  if (debug == 1) { //please note: with all these delays for the serial sending, the code will run slower than normal
    distl = analogRead(sonarl);
    distr = analogRead(sonarr);
    distf = analogRead(sonarf);
    Serial.println("left:");
    delay(500);
    Serial.println(distl);
    delay(500);
    Serial.println("right:");
    delay(500);
    Serial.println(distr);
    delay(500);
    Serial.println("front:");
    delay(500);
    Serial.println(distf);
    delay(500);
    Serial.println("motor values:");
    delay(500);
    Serial.println(servoPosition);
    delay(500);
    temp = analogRead(temp1);
    Serial.println("temp:");
    delay(500);
    Serial.println(temp);
    delay(500);
  }
}
