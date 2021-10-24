#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

//Sida 185 megaAVR® Data Sheet
#define FOSC 16000000 //Clock speed
#define BAUDRATE 38400 //Baudrate
#define BAUD_PRESCALE FOSC/16/BAUDRATE -1 //calculation for presacling

void uart_init(void) {
    //Set baud rate, two ways.
    //uint16_t ubrrn = FOSC/(16*BAUD) - 1;

        //Set them seperatly
    UBRR0H = (BAUD_PRESCALE >> 8); 
    UBRR0L = BAUD_PRESCALE;
    //Or set them both at the same time
    //UBRR0 = ubrrn;

        //UCSR0B = USART Control and Status Register B
        //RXEN = Enable receiver, TXEN0 = enable transmitter
    UCSR0B = (1<<TXEN0); 
    //UCSR0B = (1<<RXEN0);

        //The first and second bit of the USR0 register C
        //sets the number of data bits in a frame
        //the recviever and transmitter will use.
        //In this case, UCSZ01 & UCSZ00 = 1 (8bit)
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    //Type of stop bit(1)
    //UCSR0C = (0 << USBS0);  //is set to 0 by default, making this line redundant

    //Set parity to none
    //UCSR0C &= ~_BV(UPM01) & ~_BV(UPM00); //Also set to zero by default, also redundant
}

void uart_putchar(char chr) {
    while(!(UCSR0A & (1 << UDRE0))) { // while transmission is available
    }
            if(chr == '\n') { //check for prompted newline
            UDR0 = '\r';   //break input
        }
    UDR0 = chr; // load data into transmit register
}

void uart_putstr(char *str) {
    int i = 0;

    while(str[i] != '\0' ) {
        uart_putchar(str[i]); // transmit character until NULL is reached
        i++;
    }
}