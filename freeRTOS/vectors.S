.syntax unified
.cpu cortex-a9
.fpu vfpv3

.section .vectors, "ax", %progbits
.global _start
.global irq_handler

_start:
    /* Initialize stack pointer */
    ldr sp, =_stack_top

    /* Vector table */
    b reset_handler       /* 0x00 Reset */
    b undefined_handler   /* 0x04 Undefined Instruction */
    b swi_handler         /* 0x08 Software Interrupt */
    b prefetch_abort      /* 0x0C Prefetch Abort */
    b data_abort          /* 0x10 Data Abort */
    b reserved_handler    /* 0x14 Reserved */
    b irq_handler         /* 0x18 IRQ */
    b fiq_handler         /* 0x1C FIQ */

reset_handler:
    ldr sp, =_stack_top
    bl main
hang:
    b hang

undefined_handler:
    b undefined_handler

swi_handler:
    b swi_handler

prefetch_abort:
    b prefetch_abort

data_abort:
    b data_abort

reserved_handler:
    b reserved_handler

fiq_handler:
    b fiq_handler

/* IRQ Handler */
irq_handler:
    /* Save context if needed */

    /* Call C IRQ handler */
    bl irq_c_handler

    /* Return from IRQ */
    subs pc, lr, #4

/* Stack top (16 KB) */
.section .bss
.comm _stack_top, 0x4000, 0x4
