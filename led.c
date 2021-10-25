#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

#define blue 0b10
#define green 0b100
#define red 0b1000
#define RGB_INIT 0b00001110

void led_off(void) {
    PORTB = 0xff;           //Sets Port data register B to 255, which turns the led off
}

void led_init(void) {
    DDRB = DDRB | RGB_INIT;  //Set pin 9,10,11 as output
    led_off();              //turn led off to not be blinded
}

void blinkyLight(void) {
PORTB &= ~blue;    //Set pin number 9 HIGH
}

void greenLight(void) {
PORTB &= ~green;    //Set pin number 10 HIGH
}

void redLight(void) {
PORTB &= ~red;    //Set pin number 11 HIGH
}
