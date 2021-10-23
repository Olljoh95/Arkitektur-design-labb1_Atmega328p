#ifndef SERIAL_H_
#define SERIAL_H_

void uart_init(void);
    
void uart_putchar(unsigned char chr);

char uart_getchar(void);

void uart_putstr(char *str);


//void uart_echo(void);

#endif

