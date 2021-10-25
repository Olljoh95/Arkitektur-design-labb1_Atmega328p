#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

#define blue 0b10
#define green 0b100
#define red 0b1000
#define RGB_INIT 0b00001110

void led_off(void) {
    PORTB = 0xff;           //Set register B to 0
}

void led_init(void) {
    DDRB = DDRB | RGB_INIT;
    led_off();
}

void blinky_blue(void) {
PORTB &= ~blue;    //Set pin number 9 HIGH
}

void blinky_green(void) {
PORTB &= ~green;    //Set pin number 10 HIGH
}

void blinky_red(void) {
PORTB &= ~red;    //Set pin number 11 HIGH
}
