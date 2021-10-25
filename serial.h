#ifndef SERIAL_H_
#define SERIAL_H_

void uart_init(void);

void uart_putchar(unsigned char chr);

void uart_putstr(unsigned char *str);

unsigned char uart_getchar(void);

void uart_echo(void);

#endif

