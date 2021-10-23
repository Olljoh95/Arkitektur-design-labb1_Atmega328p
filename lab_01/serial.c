#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

//Sida 185 megaAVR® Data Sheet

#define FOSC 16000000 // Clock Speed
#define BAUD 38400   // BaudRate

void uart_init(void) {
    //Set baud rate, two ways.
    uint16_t ubrrn = FOSC/(16*BAUD) - 1;

    UBRR0H = (ubrrn >> 8); 
    UBRR0L = ubrrn;

    //Or set them both at the same time
    //UBRR0 = ubrrn;

    //UCSR0B = USART Control and Status Register B
    //RXEN = Enable receiver, TXEN0 = enable transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

    //Type of stop bit(1)
    UCSR0C = (0 << USBS0);
    
    //Set parity to none
    UCSR0C &= ~_BV(UPM01) & ~_BV(UPM00);

    //The first and second bit of the USR0 register C
    //sets the number of data bits in a frame
    //the recviever and transmitter will use.
    //In this case, UCSZ01 & UCSZ00 = 1 (8bit)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
void uart_putchar(unsigned char chr) {
    while(!(UCSR0A & (UDRE0 << 1))); // wait for transmit buffer to be empty
    if(chr == '\n') {
        chr = '\r';
    }
    UDR0 = chr; // load data into transmit register
}

char uart_getchar(void) {
    while(!(UCSR0A & (1 << RXC0))); //wait for data to be recieved

    return UDR0; //Get and return recieved data from buffer
}

void uart_putstr(char *str) {
    int i = 0;

    while(str[i] != '\0' ) {
        uart_putchar(str[i]); // transmit character until NULL is reached
        i++;
    } 
}