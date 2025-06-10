CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

BOOTMNT ?= /mnt/d/RaspBerryBareMetalOut/

CFLAGS = -O2 -nostdlib -ffreestanding -mcpu=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard -marm -Wall \
         -I./FreeRTOS-Kernel/include \
         -I./FreeRTOS-Kernel/portable/GCC/ARM_CA9 \
         -I.

ASFLAGS = -mcpu=cortex-a9 -mfpu=vfpv3-d16 -mfloat-abi=hard -marm --warn --fatal-warnings

LDFLAGS = -T linker.ld

OBJS = vectors.o main.o gic.o \
       FreeRTOS-Kernel/portable/GCC/ARM_CA9/portASM.o \
       FreeRTOS-Kernel/portable/GCC/ARM_CA9/port.o \
       FreeRTOS-Kernel/tasks.o \
       FreeRTOS-Kernel/list.o \
       FreeRTOS-Kernel/queue.o \
       FreeRTOS-Kernel/croutine.o \
       FreeRTOS-Kernel/event_groups.o \
       FreeRTOS-Kernel/timers.o \
       FreeRTOS-Kernel/portable/MemMang/heap_4.o \
       irq.o tick_timer.o utils.o

all: kernel7.img

vectors.o: vectors.S
	$(CC) $(CFLAGS) -c -o vectors.o vectors.S

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

gic.o: gic.c
	$(CC) $(CFLAGS) -c -o gic.o gic.c

irq.o: irq.c
	$(CC) $(CFLAGS) -c -o irq.o irq.c

tick_timer.o: tick_timer.c
	$(CC) $(CFLAGS) -c -o tick_timer.o tick_timer.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c -o utils.o utils.c

FreeRTOS-Kernel/portable/GCC/ARM_CA9/portASM.o: FreeRTOS-Kernel/portable/GCC/ARM_CA9/portASM.S
	$(CC) $(CFLAGS) -c -o FreeRTOS-Kernel/portable/GCC/ARM_CA9/portASM.o FreeRTOS-Kernel/portable/GCC/ARM_CA9/portASM.S

FreeRTOS-Kernel/portable/GCC/ARM_CA9/port.o: FreeRTOS-Kernel/portable/GCC/ARM_CA9/port.c
	$(CC) $(CFLAGS) -c -o FreeRTOS-Kernel/portable/GCC/ARM_CA9/port.o FreeRTOS-Kernel/portable/GCC/ARM_CA9/port.c

kernel7.img: $(OBJS)
	$(LD) $(LDFLAGS) -o kernel7.elf $(OBJS)
	$(OBJCOPY) -O binary kernel7.elf kernel7.img
	cp kernel7.img $(BOOTMNT)/

clean:
	rm -f *.o kernel7.elf kernel7.img
	rm -f FreeRTOS-Kernel/*.o
	rm -f FreeRTOS-Kernel/portable/GCC/ARM_CA9/*.o
	rm -f FreeRTOS-Kernel/portable/MemMang/*.o

