#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#include "led.h"

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
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

        //The first and second bit of the USR0 register C
        //sets the number of data bits in a frame
        //the recviever and transmitter will use.
        //In this case UCSZ00 = 3 (8bit), USB0 = 1 (2 stopbit)
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);

    //Set parity to none
    //UCSR0C &= ~_BV(UPM01) & ~_BV(UPM00); //Also set to zero by default, also redundant
}

void uart_putchar(unsigned char chr) {
    while(!(UCSR0A & (1 << UDRE0))) { // while transmission is available
    }
            if(chr == '\n') { //check for prompted newline
            UDR0 = '\r';   //break input
        }
    UDR0 = chr; // load data into transmit register
}

void uart_putstr(unsigned char *str) {
    int i = 0;                  //variable for iterating string
    while(str[i] != '\0' ) {
        uart_putchar(str[i]); // transmit character until NULL is reached
        i++;
    }
}

void uart_echo(void) {
    unsigned char chr = uart_getchar(); //Fetch input from UDR0
    uart_putchar(chr);                  //Send fetched char to putChar function
}

unsigned char uart_getchar(void) {
    while(!(UCSR0A & (1 << RXC0)));  //If recieve-buffer is not empty... 
    return UDR0;                    //return whats currrently in the buffer
}