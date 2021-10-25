#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
	//blinky_blue();
	//blinky_green();
	//blinky_red();
	led_init();
	uart_init();
	while(1) {
		uart_echo();
	}
}
