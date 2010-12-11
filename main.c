//-------------------------------------------
/*
main.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

int main(void) { //Main loop, runs once but can have an infinit loop in it

    bios();

    while(1) { //infinit loop that doesn't stop running. (always true since 1 is always 1
        check_buttons(); //debounces the buttons with the aid of the timer0 interrupt
        buttons(); //if a buttons been pressed, code inside of here will run, if not
        //it's skiped over. simply cleans up this part of the code
    };
    return 0; //never reached since 1 is always true
}
