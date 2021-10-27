#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
	char *cmd[8]; //Array to store USART-inputs

	led_init();
	uart_init();

	while(1) {
		//uart_echo();
		uart_buildCommand(cmd); //Fill the array with chars
		uart_executeCommand(cmd); //Compare chars to led-commands.
	}
}
