ENTRY(_start)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 0x00800000
}

SECTIONS
{
    . = ORIGIN(RAM);

    .vectors : {
        KEEP(*(.vectors))
    } > RAM

    .text : {
        *(.text*)
    } > RAM

    .data : {
        *(.data*)
    } > RAM

    .bss : {
        *(.bss*)
        *(COMMON)
    } > RAM

    /DISCARD/ : { *(.note*) *(.comment*) }
}
