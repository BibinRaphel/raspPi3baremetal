#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

#define configUSE_PREEMPTION                    1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#define configUSE_TICKLESS_IDLE                 0
#define configCPU_CLOCK_HZ                      ( 600000000UL ) // Adjust to your core clock
#define configTICK_RATE_HZ                      ( 1000 )
#define configMAX_PRIORITIES                    ( 5 )
#define configMINIMAL_STACK_SIZE                ( 128 )
#define configTOTAL_HEAP_SIZE                   ( 10240 )
#define configMAX_TASK_NAME_LEN                 ( 16 )
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1

/* Synchronization primitives */
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configQUEUE_REGISTRY_SIZE               8

/* Hook functions */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configUSE_MALLOC_FAILED_HOOK            1

/* Run-time stats */
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0

/* Co-routines */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         1

/* Software timers */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               2
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            configMINIMAL_STACK_SIZE

/* Cortex-A specific */
#define configUNIQUE_INTERRUPT_PRIORITIES       32
#define configMAX_API_CALL_INTERRUPT_PRIORITY   25

/* Required interrupt macros */
#define configINTERRUPT_CONTROLLER_BASE_ADDRESS         0xFF840000UL
#define configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET 0x1000UL

/* Tick interrupt setup (defined by you in portASM.S or a C file) */
extern void vConfigureTickInterrupt(void);
#define configSETUP_TICK_INTERRUPT()            vConfigureTickInterrupt()
#define configCLEAR_TICK_INTERRUPT()            // Empty if not used

/* Assertions */
#define configASSERT(x) if ((x) == 0) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* API functions */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           0
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1

#endif /* FREERTOS_CONFIG_H */
