#include "gic.h"


void gic_init(void)
{
    // Enable Distributor
    GICD_CTLR = 1;

    // Enable CPU interface
    GICC_CTLR = 1;

    // Set priority mask to allow all priorities through (lowest = 0xFF)
    GICC_PMR = 0xFF;

    // Enable interrupt for IRQ ID 30 (example: timer interrupt)
    GICD_ISENABLER0 = (1 << 30);
}

