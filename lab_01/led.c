#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

/*
13|12|11|10|9|8|x|x
*/

void blinky_blue() {
DDRB = DDRB | 0b10; // Sätt pin 9 till OUTPUT
PORTB = 0b0000000;      // Sätt alla pins till LOW  
    while(1){
    PORTB = 0b10;   //Sätt pin 9 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = 0b0000000; //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }    
}

void blinky_green() {
DDRB = DDRB | 0b100; // Sätt pin 10 till OUTPUT
PORTB = 0b0000000;      // Sätt alla pins till LOW  
    while(1){
    PORTB = 0b100;   //Sätt pin 10 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = 0b0000000; //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }    
}

void blinky_red() {
DDRB = DDRB | 0b1000; // Sätt pin 11 till OUTPUT
PORTB = 0b0000000;      // Sätt alla pins till LOW  
    while(1){
    PORTB = 0b1000;   //Sätt pin 11 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = 0b0000000; //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }  
}