#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
	//blinky_blue();
	//blinky_green();
	//blinky_red();
	
	char *str = "Olle J \n";
	//char *chr = 'a'; 
	uart_init();

	while(1) {
		uart_putstr(str);
		//uart_putchar(chr);
		uart_getchar();
	}


}
