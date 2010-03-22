//-------------------------------------------
/*
ADC.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode - JoshAshby
*/
//-------------------------------------------
#include "adc.h"
#include "pwm.h"
ISR(ADC_vect)
{
}
void adc_start(void)
{
    ADCSRA |= (1 << ADPS2)
            | (1 << ADPS1)
            | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz
    ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
    ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading
    ADCSRA |= (1 << ADATE);
    ADCSRA |= (1 << ADEN);  // Enable ADC
    ADCSRA |= (1 << ADIE);  // Enable ADC Interrupt
    sei();
    ADCSRA |= (1 << ADSC);  // Start A2D Conversions
}
void adc_stop(){
    //stop the ADC
    ADCSRA |= (0 << ADSC);
}
void adc_change(int chan){
    //stop the ADC
    ADCSRA |= (0 << ADSC);
    //and now change the ADMUX bits to fit which channal you want to use, this should probably be replaced by a switch soon
    switch (chan) {
        case 0:
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 1:
            ADMUX |= (1 << MUX0)
                  &  ~(1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 2:
            ADMUX &= ~(1 << MUX0)
                  |  (1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 3:
            ADMUX |= (1 << MUX0)
                  |  (1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 4:
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1)
                  |  (1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 5:
            ADMUX |= (1 << MUX0)
                  &  ~(1 << MUX1)
                  |  (1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 6:
            ADMUX &= ~(1 << MUX0)
                  |  (1 << MUX1)
                  |  (1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 7:
            ADMUX |= (1 << MUX0)
                  |  (1 << MUX1)
                  |  (1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 8:
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1)
                  &  ~(1 << MUX2)
                  |  (1 << MUX3);
            break;
    }
/*    if (chan == 0) {
        ADMUX |= (0 << MUX0);
    }
    if (chan == 1) {
        ADMUX |= (1 << MUX0);
    }
    if (chan == 2) {
        ADMUX |= (1 << MUX1);
    }
    if (chan == 3) {
        ADMUX |= (1 << MUX0)
               | (1 << MUX1);
    }
    if (chan == 4) {
        ADMUX |= (1 << MUX2);
    }
    if (chan == 5) {
        ADMUX |= (1 << MUX0)
               | (1 << MUX2);
    }
    if (chan == 6) {
        ADMUX |= (1 << MUX1)
               | (1 << MUX2);
    }
    if (chan == 7) {
        ADMUX |= (1 << MUX0)
               | (1 << MUX1)
               | (1 << MUX2);
    }
    if (chan == 8) {
        ADMUX |= (1 << MUX3);
    }*/
    ADCSRA |= (1 << ADSC);
}
