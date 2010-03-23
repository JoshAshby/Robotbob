#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
#include <util/delay.h>
//-------------------------------------------
/*
robotfunc.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
void turn_left(void){
    if (dirrection == 0) {
        if (ultrasound_filter(4) > base && ultrasound_filter(5) > base)
        {
            out('D', 4, 1);
            _delay_ms(5);
            pwm1B(255);
            _delay_ms(200);
            pwm1B(0);
            out('D', 4, 0);
        }
    } else {
        out('D', 4, 1);
        _delay_ms(5);
        pwm1B(255);
        _delay_ms(200);
        pwm1B(0);
        out('D', 4, 0);
    }
}
void turn_right(void){
    if (dirrection == 1){
        if (ultrasound_filter(4) > base && ultrasound_filter(5) > base)
        {
            pwm1B(255);
            _delay_ms(200);
            pwm1B(0);
        }
    } else {
        pwm1B(255);
        _delay_ms(200);
        pwm1B(0);
    }
}
void stop(void){
    pwm0A(0);
    pwm0B(0);
    pwm1A(0);
    pwm1B(0);
    pwm2A(0);
    pwm2B(0);
    out('D', 2, 1);
    error(1);
    out('D', 4, 0);
    out('D', 5, 0);
}
void calibrate(void){
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
int ultrasound_filter(int pin){
    /*simple filter that works quite well, it simply smooths out the ADC data from the ultrasounds
    if the ADCH data is out of range, it will divide it by two, and then add the average divided by two*/
    adc_change(pin);
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
    average = average/20;
    return average;
}
void ultrasound_test(void){
    if (ultrasound_filter(4) >= base) {
        out('D', 2, 0);
        pwm2B(ultrasound_filter(5));
    } else {
        out('D', 2, 1);
        pwm2B(ultrasound_filter(4));
    }
}
