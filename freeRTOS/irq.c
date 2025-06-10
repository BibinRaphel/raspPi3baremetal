#if 0
void irq_c_handler(void) {
    // Your IRQ handling code here
}
#endif

#include "gic.h"

#define TIMER_IRQ 30  // Replace with your timer IRQ number
#define UART_IRQ 33   // Replace with your UART IRQ number

void timer_interrupt_handler(void) {
    // Clear timer interrupt flag, reload timer, etc.
}

void uart_interrupt_handler(void) {
    // Read UART status, clear interrupt, handle RX/TX
}

void irq_c_handler(void)
{
    uint32_t irq_id = gic_get_irq();

    switch (irq_id) {
        case TIMER_IRQ:
            timer_interrupt_handler();
            break;
        case UART_IRQ:
            uart_interrupt_handler();
            break;
        default:
            // Unknown or spurious interrupt
            break;
    }

    gic_acknowledge_irq(irq_id);
}
