#include <stdint.h>

/* Generic Timer registers in CNTPS* */
#define CNTFRQ_EL0    (*(volatile uint32_t *)0x00000000)  // Normally read from system register, you may need inline asm
#define CNTP_TVAL    (*(volatile uint32_t *)0x00000000)   // timer value register (system register)
#define CNTP_CTL     (*(volatile uint32_t *)0x00000000)   // control register (system register)

static void vSetupTickInterrupt(void) {
    uint32_t timer_freq;

    /* Read timer frequency - use assembly to read CNTFRQ_EL0 */
    __asm volatile ("mrs %0, cntfrq_el0" : "=r" (timer_freq));

    /* Configure timer to interrupt every 1ms */
    uint32_t ticks = timer_freq / 1000;

    __asm volatile ("msr cntp_tval_el0, %0" : : "r" (ticks));
    __asm volatile ("msr cntp_ctl_el0, %0" : : "r" (1));  /* Enable timer and unmask interrupt */
}

static void vClearTickInterrupt(void) {
    /* Writing to CNTP_CTL register can clear the interrupt */
    __asm volatile ("msr cntp_ctl_el0, %0" : : "r" (1));  /* Re-enable timer */
}

void vConfigureTickInterrupt(void) {
    // Code to configure timer interrupt for FreeRTOS tick
}
