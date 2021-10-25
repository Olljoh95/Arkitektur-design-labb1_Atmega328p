#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

#define blue 0b10
#define green 0b100
#define red 0b1000
#define off 0b0000000

void led_off(void) {
    PORTB = off;           //Set register B to 0
}

void blinky_blue(void) {
DDRB = DDRB | blue;         //Set pin 9 to OUTPUT  
PORTB = (1 << 1);    //Set pin number 9 HIGH
}

void blinky_green(void) {
DDRB = DDRB | green;      //Set pin 10 TO OUTPUT
PORTB = (1 << 3);    //Set pin number 10 HIGH
}

void blinky_red(void) {
DDRB = DDRB | red;       //Set pin 11 to OUTPUT
PORTB = (1 << 4);    //Set pin number 11 HIGH
}
