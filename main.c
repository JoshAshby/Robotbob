#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
//-------------------------------------------
int pwm_start(void);
int pwm(int value, int pin, int speed);
int pwm_ramp(int value, int pin, int speed);
int pwm_value;

ISR(ADC_vect)
{
   pwm(ADCH, 0, 0);
}
//-------------------------------------------
int main(void)
{
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128 - 125KHz sample rate @ 16MHz

    ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
    ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading
    ADCSRA |= (1 << ADATE);  // Set ADC to Free-Running Mode
    ADCSRA |= (1 << ADEN);  // Enable ADC
    ADCSRA |= (1 << ADIE);  // Enable ADC Interrupt
    sei();   // Enable Global Interrupts
    ADCSRA |= (1 << ADSC);  // Start A2D Conversions
    pwm_start();
    for(;;){
    }
return 0;   //  never reached
}
//--------------------------------------
//start the pwm timer for the OCR1A pin, and set the default pem_value level
//this should only have to be called once
int pwm_start(void)
{
    OCR1AH = 0;
    DDRB |= (1<<1);
    DDRB |= (1<<2);
    TCCR1A = (1<<COM1A1)|(1<<1);
    TCCR1B = 1;
    pwm_value = 0;
    return 1;
}
//for the moment just a dummy function that passes everything on to pwm_ramp
int pwm(int value, int pin, int speed)
{
    pwm_ramp(value, pin, speed);
    return 1;
}
//smart function that will ramp up or down the pwm to the given value, and will increase and decrease the value
//at speed given (in milliseconds, this is how long between each value increase at the moment)
int pwm_ramp(int value, int pin, int speed)
{
    if (value < pwm_value) {
        if (pin == 0) {
            int i;
            for (i=pwm_value; i>=value; i--) {
                OCR1AL = i;
                pwm_value = i;
                _delay_ms(speed);
            }
        }
        if (pin == 1) {
            int i;
            for (i=pwm_value; i>=value; i--) {
                OCR1BL = i;
                pwm_value = i;
                _delay_ms(speed);
            }
        }
    } else {
        if (pin == 0) {
            int i;
            for (i=0; i<=value; i++) {
                OCR1AL = i;
                pwm_value = i;
                _delay_ms(speed);
            }
        }
        if (pin == 1) {
            int i;
            for (i=0; i<=value; i++) {
                OCR1BL = i;
                pwm_value = i;
                _delay_ms(speed);
            }
        }
    }
    return 1;
}
