#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

#define blue 0b10
#define green 0b100
#define red 0b1000
#define off 0b0000000

void blinky_blue() {
DDRB = DDRB | blue;  // Sätt pin 9 till OUTPUT
PORTB = off;        // Sätt alla pins till LOW  
    while(1){
    PORTB = (1 << 1);    //Sätt pin 9 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = off;       //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }    
}

void blinky_green() {
DDRB = DDRB | green; // Sätt pin 10 till OUTPUT
PORTB = off;        // Sätt alla pins till LOW  
    while(1){
    PORTB = (1 << 3);    //Sätt pin 10 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = off;       //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }    
}

void blinky_red() {
DDRB = DDRB | red; // Sätt pin 11 till OUTPUT
PORTB = off;      // Sätt alla pins till LOW  
    while(1){
    PORTB = (1 << 4);    //Sätt pin 11 till HIGH 
     _delay_ms(500);    //Vänta 500 ms
    PORTB = off;       //Sätt alla pinnar till LOW 
    _delay_ms(500);   //Vänta 500 ms
    }  
}
