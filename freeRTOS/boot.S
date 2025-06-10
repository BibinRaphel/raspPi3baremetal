.global _start
.section .text.startup

_start:
    ldr sp, =_stack_top

    bl main

hang:
    b hang

.section .bss
.bss_start:
    .skip 4096
.bss_end:

.section .stack
_stack:
    .space 4096
_stack_top:
