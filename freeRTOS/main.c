#include <stdint.h>
#include "FreeRTOS.h"

extern void gic_init(void);
#define PERIPHERAL_BASE 0x3F000000
#define GPIO_BASE       (PERIPHERAL_BASE + 0x200000)
#define GPFSEL1         (*(volatile unsigned int *)(GPIO_BASE + 0x04))
#define GPSET0          (*(volatile unsigned int *)(GPIO_BASE + 0x1C))
#define GPCLR0          (*(volatile unsigned int *)(GPIO_BASE + 0x28))
#define GPIO_PIN        16

extern void irq_c_handler(void);

void gpio_init(void)
{
    // Set GPIO16 as output
    GPFSEL1 &= ~(7 << 18);  // Clear bits for FSEL16
    GPFSEL1 |=  (1 << 18);  // Set as output (001)
}

void gpio_set(void)
{
    GPSET0 = (1 << GPIO_PIN);
}

void gpio_clear(void)
{
    GPCLR0 = (1 << GPIO_PIN);
}

void led_blink_task(void *params)
{
    while (1)
    {
        gpio_set();
        vTaskDelay(pdMS_TO_TICKS(500));  // 500ms on
        gpio_clear();
        vTaskDelay(pdMS_TO_TICKS(500));  // 500ms off
    }
}

void vApplicationMallocFailedHook(void)
{
    // Optionally handle malloc failure (e.g., error log or halt)
    for(;;); // Loop forever to catch error
}

int main(void)
{
    /* Initialize GIC to enable timer IRQ */
    gic_init();
    gpio_init();

    /* Enable IRQs */
    __asm volatile ("cpsie i");

    /* Initialize FreeRTOS, create tasks, etc. here */
    xTaskCreate(led_blink_task, "LED Blink", 128, NULL, 1, NULL);
    vTaskStartScheduler();

    while (1);  // Should never reach here
}
