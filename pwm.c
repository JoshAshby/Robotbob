//-------------------------------------------
/*
PWM.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

/** \brief Sets up all the timers on the chip for PWM fast output with prescalers of 64. Useless on BOB as he only uses timer1 for PWM and timer0 and timer2 for interrupts
 *
 * \param void - Takes no arguments
 * \return void - Returns nothing
 *
 */
void pwm_setup_all(void) {
    TCCR0B |= (1<<CS00)
            | (1<<CS01); //set timerO clock prescaler to 64
    TCCR0A |= (1<<WGM00);//fast pwm with top as 0xFF

    DDRD |= (1<<5);
    DDRD |= (1<<6); //set the OCR0 pins as outputs

    TCCR1B |= (1<<CS11)
            | (1<<CS10);//set timer1 clock prescaler to 64
    TCCR1A |= (1<<WGM10)
            | (1<<WGM11); //fast pwm (10bit) with top as 0x03FF

    DDRB |= (1<<1);
    DDRB |= (1<<2);//set the OCR1 pins as outputs

    TCCR2B |= (1<<CS22);//set timer2 clock prescaler to 64
    TCCR2A |= (1<<WGM20);//fast pwm with top as 0xFF

    DDRD |= (1<<3);
    DDRB |= (1<<3); //set the OCR2 pins as outputs
}

/** \brief Sets up timer0 for fast PWM with prescaler 64
 *
 * \param void - Takes no arguments
 * \return void - Returns nothing
 *
 */
void pwm_setup0(void) {
    TCCR0B |= (1<<CS00)
            | (1<<CS01);//set timerO clock prescaler to 64
    TCCR0A |= (1<<WGM00);//fast pwm with top as 0xFF

    DDRD |= (1<<5);
    DDRD |= (1<<6);//set the OCR0 pins as outputs
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR0A
 *
 * \param value uint8_t - The 8bit long value which timer0's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm0A(uint8_t value) {
    TCCR0A |= (1<<COM0A1);
    OCR0A = value;
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR0B
 *
 * \param value uint8_t - The 8bit long value which timer0's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm0B(uint8_t value) {
    TCCR0A |= (1<<COM0B1);
    OCR0B = value;
}

/** \brief Sets up timer1 (16Bit PWM/Timer) for fast PWM with prescaler 64
 *
 * \param void - Takes no arguments
 * \return void - Returns nothing
 *
 */
void pwm_setup1(void) {
    TCCR1B |= (1<<CS11)
            | (1<<CS10);//set timer1 clock prescaler to 64
    TCCR1A |= (1<<WGM11)
            | (1<<WGM12)
            | (1<<WGM13); //fast pwm (16bit) with top as 0x03FF
    //ICR1H = 0xFF; //set IRC1 to max for full 16bit resolution
    //IRC1L = 0xFF;

    DDRB |= (1<<1);
    DDRB |= (1<<2);//set the OCR2 pins as outputs
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR1A
 *
 * \param value uint16_t - The 16bit long value which timer1's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm1A(uint16_t value) {
    TCCR1A |= (1<<COM1A1);
    OCR1A = value;
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR1B
 *
 * \param value uint16_t - The 16bit long value which timer1's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm1B(uint16_t value) {
    TCCR1A |= (1<<COM1B1);
    OCR1B = value;
}

/** \brief Sets up timer2 for fast PWM with prescaler 64
 *
 * \param void - Takes no arguments
 * \return void - Returns nothing
 *
 */
void pwm_setup2(void) {
    TCCR2B |= (1<<CS22);//set timer2 clock prescaler to 64
    TCCR2A |= (1<<WGM20);//fast pwm with top as 0xFF

    DDRD |= (1<<3);
    DDRB |= (1<<3); //set the OCR2 pins as outputs
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR2A
 *
 * \param value uint8_t - The 8bit long value which timer2's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm2A(uint8_t value) {
    TCCR2A |= (1<<COM2A1);
    OCR2A = value;
}

/** \brief Sets the PWM duty cycle to the value passed to it in the value variable for OCR2B
 *
 * \param value uint8_t - The 8bit long value which timer2's PWM duty is set to
 * \return void - Returns nothing
 *
 */
void pwm2B(uint8_t value) {
    TCCR2A |= (1<<COM2B1);
    OCR2B = value;
}
