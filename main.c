#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
	char *cmd[20];

	led_init();
	uart_init();

	while(1) {
		//uart_echo();
		uart_buildCommand(cmd);
		if(strcmp(cmd, "blue\r\n") == 0) {
        	blueLight();
    	}
    	else if(strcmp(cmd, "green\r\n") == 0) {
        	greenLight();
    	}
    	else if(strcmp(cmd, "red\r\n") == 0) {
        	redLight();
    	}
    	else {
        	led_off();
    	}
	}
}
