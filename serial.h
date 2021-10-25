#ifndef SERIAL_H_
#define SERIAL_H_

void uart_init(void);

void uart_putchar(unsigned char chr);

void uart_putstr(unsigned char *str);

void uart_getchar(void);

unsigned char uart_echo(void);

#endif

