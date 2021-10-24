#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
	//blinky_blue();
	//blinky_green();
	//blinky_red();

	//char chr = 'h';
	//char chr2 = 'j';
	//char chr1 = 'e';
	//char stop = '\n';
	char *str = "Olle J \n";


	uart_init();
	
	while(1) {
		//uart_putchar(chr);
		//uart_putchar(chr1);
		//uart_putchar(chr2);
		//uart_putchar(stop);
		uart_putstr(str);
	}

}
