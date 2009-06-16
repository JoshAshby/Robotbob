#!/usr/bin/env python
import serial
usbport = '/dev/ttyUSB0'
ser = serial.Serial(usbport, 9600, timeout=1)
def move(servo, angle):
    ser.write(chr(255))
    ser.write(chr(servo))
    ser.write(chr(angle))
