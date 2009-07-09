#!/usr/bin/env python
import serial #import the serial comunication library
usbport = '/dev/ttyUSB0'
ser = serial.Serial(usbport, 9600, timeout=1)
def move(motor, speed, fb):
    ser.write(chr(255))
    ser.write(chr(motor))
    ser.write(chr(speed))
    ser.write(chr(fb))