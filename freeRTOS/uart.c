#include <stdint.h>
#include "uart.h"

#define UART0_BASE 0x3F201000
#define UART0_FR   (*(volatile uint32_t *)(UART0_BASE + 0x18))
#define UART0_DR   (*(volatile uint32_t *)(UART0_BASE + 0x00))

void uart_putc(char c) {
    while (UART0_FR & (1 << 5));
    UART0_DR = c;
}

void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}
