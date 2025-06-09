#include <stdint.h>

extern void gic_init(void);
extern void irq_c_handler(void);

void vApplicationMallocFailedHook(void)
{
    // Optionally handle malloc failure (e.g., error log or halt)
    for(;;); // Loop forever to catch error
}


void main(void) {
    /* Initialize GIC to enable timer IRQ */
    gic_init();

    /* Enable IRQs */
    __asm volatile ("cpsie i");

    /* Initialize FreeRTOS, create tasks, etc. here */

    while (1) {
        /* Main loop */
    }
}
