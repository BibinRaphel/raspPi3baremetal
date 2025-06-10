
#include <stdint.h>


#define GIC_DIST_BASE 0xF9000000
#define GIC_CPU_BASE  0xF9001000

#define GICD_CTLR     (*(volatile unsigned int *)(GIC_DIST_BASE + 0x000))
#define GICD_ISENABLER0 (*(volatile unsigned int *)(GIC_DIST_BASE + 0x100))

#define GICC_CTLR     (*(volatile unsigned int *)(GIC_CPU_BASE + 0x000))
#define GICC_PMR      (*(volatile unsigned int *)(GIC_CPU_BASE + 0x004))
#define GICC_IAR      (*(volatile unsigned int *)(GIC_CPU_BASE + 0x00C))
#define GICC_EOIR     (*(volatile unsigned int *)(GIC_CPU_BASE + 0x010))
#define GIC_DIST_ACK  (*(volatile unsigned int *)(GIC_CPU_BASE + 0x0C))


// Signal end of interrupt
inline void gic_acknowledge_irq(uint32_t irq_id)
{
    GICC_EOIR = irq_id;
}

// Get the active interrupt ID
inline uint32_t gic_get_irq(void)
{
    return GIC_DIST_ACK;
}
