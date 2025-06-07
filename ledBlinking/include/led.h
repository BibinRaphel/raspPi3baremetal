#pragma once

#include "peripherals/gpio.h"

typedef enum _GpioFunc {
    GFInput = 0,
    GFOutput = 1,
    GFAlt0 = 4,
    GFAlt1 = 5,
    GFAlt2 = 6,
    GFAlt3 = 7,
    GFAlt4 = 3,
    GFAlt5 = 2
} GpioFunc;

void gpio_pin_set_func(u8 pinNumber, GpioFunc func);

void gpio_pin_enable(u8 pinNumber);


#define REGS_GPIO ((struct GpioRegs *)(PBASE + 0x00200000))

#define GPIO_BASE (PBASE + 0x200000)
#define GPFSEL1   ((volatile unsigned int*)(GPIO_BASE + 0x04))
#define GPSET0    ((volatile unsigned int*)(GPIO_BASE + 0x1C))
#define GPCLR0    ((volatile unsigned int*)(GPIO_BASE + 0x28))