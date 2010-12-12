//-------------------------------------------
/*
uart.c
2010 - Josh Ashby
joshuaashby@joshashby.com
http://joshashby.com
http://github.com/JoshAshby
freenode/#linuxandsci - JoshAshby
*/
//-------------------------------------------
#include "global.h"

//Got through and set up the registers for UART
/** \brief Sets up the registers and starts the UART for a baud of 9600
 *
 * \param void - Takes nothing
 * \return void - Returns nothing
 *
 */
void uart_start(void) {
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); //transmit side of hardware
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); //receive side of hardware

    UBRR0L = BAUD_PRESCALE; //set the baud to 9600, have to split it into the two registers
    UBRR0H = (BAUD_PRESCALE >> 8); //high end of baud register

    UCSR0B |= (1 << RXCIE0); //recieve data interrupt, makes sure we don't loose data
    sei(); //enable system interrupts

    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\n';//send a new line just to be sure
	while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\r';//send a new line just to be sure
}

/** \brief Send an 8bit long piece of data
 *
 * \param data uint8_t - The 8bit long data
 * \return void - Returns nothing
 *
 */
void uart_sendint(uint8_t data) {
    /*
    Use this to send a 8bit long piece of data
    */
    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
    UDR0 = data; //send the data
    /*while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\n';//send a new line just to be sure
	while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\r';//send a new line just to be sure*/
}

/** \brief Send a 16bit long piece of data
 *
 * \param data uint16_t - The 16bit long data
 * \return void - Returns nothing
 *
 */
void uart_sendint16(uint16_t data) {
    /*
    Use this to send a 16bit long piece of data
    */
    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
    UDR0 = data;//send the lower bits
    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
    UDR0 = (data >> 8); //send the higher bits
    /*
    while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\n';//send a new line just to be sure
	while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\r';//send a new line just to be sure*/
}

/** \brief Sends either a single piece of data stored as a char, or sends a string. (If sending a string, avr-gcc will yell a warning at you, you can ignore it)
 *
 * \param data char* - The char data, or a string
 * \return void - Returns nothing
 *
 */
void uart_sendchar(char *data) {
    /*
    Use this to send a string, it will split it up into individual parts
    send those parts, and then send the new line code
    */
    while (*data) {
        while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
		UDR0 = *data; //goes through and splits the string into individual bits, sends them
		data += 1;//go to new bit in string
	}/*
	while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\n';//send a new line just to be sure
	while ((UCSR0A & (1 << UDRE0)) == 0);//make sure the data register is cleared
	UDR0 = '\r';//send a new line just to be sure*/
}

/** \brief Returns the data which was stored in the recieve register and retreived by the interrupt
 *
 * \param void - Takes nothing
 * \return uint8_t - The data in the form of an 8bit long piece of data
 *
 */
uint8_t uart_get(void) {
    /*
    gets data from the register that the interrupt stored it
    in coming data into, returning it to the calling function as 8 bit long data
    */
    UCSR0B |= (1<<RXCIE0);

    sei();
	sleep_mode();
	cli();
	uint8_t b;
    if(read_spot == 0)
		b = input_buffer[sizeof(input_buffer) - 1];
	else
		b = input_buffer[read_spot - 1];
    if(b == '\r')
        b = '\n';
	return b;
}

ISR(USART_RX_vect) {//sets up the interrupt to recieve any data coming in
	input_buffer[read_spot] = UDR0;
	read_spot++;//and "exports" if you will the data to a variable outside of the register
	//until the main program has time to read it. makes sure data isn't lost as much
	if(read_spot == BUFF_LEN) read_spot = 0;
}
