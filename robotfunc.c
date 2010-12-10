//-------------------------------------------
/*
robotfunc.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

void calibrate(void) {
    /*
    sets up the rolling average, and fills it with data but only once,
    This is ran once and only once at the very begining of the code for BOB because it
    tells BOB how far from the wall he should be
    */
    adc_change(5);
    _delay_ms(20);
    adc = ADCH;
    for (j = 0; j <= 20; j++){
        if (ADCH > average + 100)
        {
            adc = (ADCH/2) + (average/2);
        }
        if (ADCH < average - 100){
            adc = (ADCH/2) + (average/2);
        }
        rollAverage[j] = adc;
    }
    for (j = 0; j <= 20; j++){
        average += rollAverage[j];
    }
    average = average/18;
    base = average;
    for (j = 0; j <= 20; j++){
        rollAverage[j] = 0;
    }
}

int ultrasound_filter(int pin) {
    /*
    simple filter that works quite well, it simply smooths out the ADC data from the ultrasounds
    if the ADCH data is out of range, it will divide it by two, and then add the average divided by two
        */
    adc_change(pin);
    _delay_ms(20);
    adc = ADCH;
    for (j = 0; j <= 30; j++){
        if (ADCH > average + 100)
        {
            adc = (ADCH/2) + (average/2);
        }
        if (ADCH < average - 100){
            adc = (ADCH/2) + (average/2);
        }
        rollAverage[j] = adc;
    }
    for (j = 0; j <= 30; j++){
        average += rollAverage[j];
    }
    average = average/30;
    return average;
}
