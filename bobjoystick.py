#!/usr/bin/env python
#This script requires the following Python modules:
#  pygame   - http://www.pygame.org/
#  motor
import motor
import pygame
# allow multiple joysticks
joy = []
# handle joystick event
def handleJoyEvent(e):
    if e.type == pygame.JOYAXISMOTION:
        axis = "unknown"
        if (e.dict['axis'] == 0):
            axis = "X"

        if (e.dict['axis'] == 1):
            axis = "Y"

        if (axis != "unknown"):
            str = "Axis: %s; Value: %f" % (axis, e.dict['value'])
#x axis of the joystick, this controlls the speed and direction
            if (axis == "X"):
                pos = e.dict['value']
                # convert joystick position to servo increment, 0-180
                move = round(pos * 90, 0)
                if (move < 0):
                    speed = int(90 - abs(move))
                    fb = 253 #forwards
                else:
                    speed = int(move + 90)
                    fb = 254 #go backwards
                # and send to robot over serial connection
                motor.move(1, speed, fb)
#y axis of the joystick, this controlls the steering
            if (axis == "Y"):
                pos = e.dict['value']
                # convert joystick position to servo increment, 0-180
                move = round(pos * 90, 0)
                if (move < 0):
                    speed = int(90 - abs(move))
                    fb = 253
                else:
                    speed = int(move + 90)
                    fb = 254
                # and send to Arduino over serial connection
                motor.move(2, speed, fb)
    elif e.type == pygame.JOYBUTTONDOWN:
        str = "Button: %d" % (e.dict['button'])
        # Button 0 (trigger) to quit
        if (e.dict['button'] == 0):
            print "Do i have to quit?\n"
            quit()
    else:
        pass
# wait for joystick input
def joystickControl():
    while True:
        e = pygame.event.wait()
        if (e.type == pygame.JOYAXISMOTION or e.type == pygame.JOYBUTTONDOWN):
            handleJoyEvent(e)
# main method
def main():
    # initialize pygame
    pygame.joystick.init()
    pygame.display.init()
    if not pygame.joystick.get_count():
        print "\nI could not find a joystick, please plug one in, or un-plug and re-plug back in your current joystick.\n"
        quit()
    print "\n%d joystick detected." % pygame.joystick.get_count()
    for i in range(pygame.joystick.get_count()):
        myjoy = pygame.joystick.Joystick(i)
        myjoy.init()
        joy.append(myjoy)
        print "Joystick %d: " % (i) + joy[i].get_name()
    print "Pull trigger (button 0) to quit.\n"
    # run joystick listener loop
    joystickControl()
# allow use as a module or standalone script
if __name__ == "__main__":
    main()