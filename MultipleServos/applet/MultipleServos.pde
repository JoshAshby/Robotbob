//ABug teleoperated control made for use with the python computer stack for joystick control
int pinArray[4] = {2, 9, 10, 4};
int i;              // iterator
int servoPosition;
int servoPin;       // control pin for current servo
int userInput[3];   // raw input from serial buffer, 3 bytes
int servo;          // which servo to pulse? 1-4
int servo1[2];      // servo #1 array{pin, pulsewidth}
int servo2[2];      // servo #2 array{pin, pulsewidth}
int servo3[2];      // servo #3 array{pin, pulsewidth}
int servo4[2];      // servo #4 array{pin, pulsewidth}
int startbyte;      // start byte, begin reading input
int relay1 = 2;
int relay2 = 4;

void setup() {
  for (i=0;i<4;i++) {
    pinMode(pinArray[i], OUTPUT);
  }  
  servo1[0] = pinArray[0];  // servo #1 is pin 2
  servo2[0] = pinArray[1];  // servo #2 is pin 3
  servo3[0] = pinArray[2];  // servo #3 is pin 4
  servo4[0] = pinArray[3];  // servo #4 is pin 5
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 2) {
    startbyte = Serial.read();
    if (startbyte == 255) {
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      servo = userInput[0];
      servoPosition = userInput[1];
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
  analogWrite(servo2[0], servo2[1]);
  analogWrite(servo3[0], servo2[1]);
  if (servo2[1] == 99)
  {
     analogWrite(relay1, 1024);
  }
  else if (servo1[1] == 96)
  {
    analogWrite(relay2, 1024);
  }
  else if (servo1[1] == 97)
  {
    analogWrite(relay2, 1024);
  }
  else if (servo1[1] == 0)
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
  }
}
