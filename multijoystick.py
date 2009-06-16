#!/usr/bin/env python
import servo
import pygame
joy = []
def handleJoyEvent(e):
    if e.type == pygame.JOYAXISMOTION:
        axis = "unknown"
        if (e.dict['axis'] == 0):
            axis = "X"
        if (e.dict['axis'] == 1):
            axis = "Y"
        if (e.dict['axis'] == 2):
            axis = "Throttle"
        if (e.dict['axis'] == 3):
            axis = "Z"
        if (axis != "unknown"):
            str = "Axis: %s; Value: %f" % (axis, e.dict['value'])
            if (axis == "X"):
                pos = e.dict['value']
                move = round(pos * 150, 0)
                if (move < 180):
                    serv = int(97)
                if (move > 0):
                    serv = int(96)
		if (move == 0):
		    serv = int(move)
                servoPosition = serv
                servo.move(1, servoPosition)
		print(move)
            if (axis == "Y"):
                pos = e.dict['value']
                move = round(pos * 150, 0)
                if (move < 180):
                    serv = int(100 - move)
                if (move > 0):
                    serv = 99
		if (move == 0):
		    serv = int(move)
                servoPosition = serv
                servo.move(2, servoPosition)
		print(move)
            if (axis == "Z"):
                pos = e.dict['value']
                move = round(pos * 100, 0)
                if (move < 180):
                    serv = int(100 - move)
                if (move > 0):
                    serv = 99
		if (move == 0):
		    serv = int(move)
                servoPosition = serv
                servo.move(3, servoPosition)
            if (axis == "Throttle"):
                pos = e.dict['value']
                move = round(pos * 100, 0)
                if (move < 180):
                    serv = int(100 - move)
                if (move > 0):
                    serv = 99
		if (move == 0):
		    serv = int(move)
                servoPosition = serv
                servo.move(4, servoPosition)
    elif e.type == pygame.JOYBUTTONDOWN:
        str = "Button: %d" % (e.dict['button'])
        if (e.dict['button'] == 0):
            print "Bye!\n"
            quit()
    else:
        pass
def output(line, stick):
    print "Joystick: %d; %s" % (stick, line)
def joystickControl():
    while True:
        e = pygame.event.wait()
        if (e.type == pygame.JOYAXISMOTION or e.type == pygame.JOYBUTTONDOWN):
            handleJoyEvent(e)
def main():
    # initialize pygame
    pygame.joystick.init()
    pygame.display.init()
    if not pygame.joystick.get_count():
        print "\nPlease connect a joystick and run again.\n"
        quit()
    print "\n%d joystick(s) detected." % pygame.joystick.get_count()
    for i in range(pygame.joystick.get_count()):
        myjoy = pygame.joystick.Joystick(i)
        myjoy.init()
        joy.append(myjoy)
        print "Joystick %d: " % (i) + joy[i].get_name()
    print "Depress trigger (button 0) to quit.\n"
    joystickControl()
if __name__ == "__main__":
    main()
