int pinArray[2] = {9, 10}; // digital pins for the motors
int i;              // iterator
int motor;          // control pin for current servo
int userInput[4];   // raw input from serial buffer, 3 bytes
int motorspeed;          // commanded speed
int motorf[2];      // motorfront #1 array{pin, pulsewidth}
int motorb[2];      // motorback #2 array{pin, pulsewidth}
int pin;            // digital pin for pulse() function
int puls;           // pulsewidth for pulse() function
int startbyte;      // start byte, begin reading input
int relayf = 2;     //front relay
int relayb = 3;     //back relay
int motordirection; //which way?
int fb = 0;         //convert the python which way to a value the arduino can use

void setup() {
  // loop through all 4 servo pins
  // and set them as OUTPUT
  for (i=0;i<2;i++) {
    pinMode(pinArray[i], OUTPUT);
  }  
  // map pins to motor controllers
  motorf[0] = pinArray[0];  // front motor is pin 9
  motorb[0] = pinArray[1];  // back motor is pin 10
  Serial.begin(9600);
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
        fb = 0; //if the motor direction is 253 then turn off the relay
      }
      if (motordirection == 254) {
        fb = 1023; //if the motor direction is 254 then turn on the relay
      }
      switch (motor) {
        case 1:
          motorf[1] = motorspeed;
          relayf = fb;
          break;
        case 2:
          motorb[1] = motorspeed;
          relayb = fb;
          break;
      }
    }
  }
}

