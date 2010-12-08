//-------------------------------------------
/*
ADC.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
/*
Information about this file and all the registers used in it
can be found on page 251 section 23 of the Atmega datasheet
*/
//-------------------------------------------
#include "adc.h"
#include "pwm.h"
#include "digital.h"
#include "boot.h"
#include "global.h"
#include "robotfunc.h"
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
    //stop the ADC by clearing the ADSC bit
    ADCSRA &= ~(1 << ADSC);
}
void adc_change(int chan){
    //stop the ADC
    ADCSRA &= ~(1 << ADSC);
    //and now change the ADMUX bits to fit which channal you want to use, this should probably be replaced by a switch soon
    switch (chan) {
        case 0: //For ADC0 the data sheet says that all MUX bits in ADMUX need to be cleared.
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 1: //for ADC1 MUX0 bit is set, but others cleared
            ADMUX |=  (1 << MUX0);
            ADMUX &= ~(1 << MUX1)
                  &  ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 2: //for ADC2 MUX1 bit is set, but others cleared
            ADMUX &= ~(1 << MUX0);
            ADMUX |=  (1 << MUX1);
            ADMUX &= ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 3: //for ADC3 MUX0 and MUX1 bits are set, but others cleared (see a pattern, this is binary
                // 1100
            ADMUX |=  (1 << MUX0)
                  |   (1 << MUX1);
            ADMUX &= ~(1 << MUX2)
                  &  ~(1 << MUX3);
            break;
        case 4:
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1);
            ADMUX |=  (1 << MUX2);
            ADMUX &= ~(1 << MUX3);
            break;
        case 5:
            ADMUX |=  (1 << MUX0);
            ADMUX &= ~(1 << MUX1);
            ADMUX |=  (1 << MUX2);
            ADMUX &= ~(1 << MUX3);
            break;
        case 6:
            ADMUX &= ~(1 << MUX0);
            ADMUX |=  (1 << MUX1)
                  |   (1 << MUX2);
            ADMUX &= ~(1 << MUX3);
            break;
        case 7:
            ADMUX |=  (1 << MUX0)
                  |   (1 << MUX1)
                  |   (1 << MUX2);
            ADMUX &= ~(1 << MUX3);
            break;
        case 8:
            ADMUX &= ~(1 << MUX0)
                  &  ~(1 << MUX1)
                  &  ~(1 << MUX2);
            ADMUX |=  (1 << MUX3);
            break;
    }
    ADCSRA |= (1 << ADSC);
}
