#define RUNTIME_TASK_COUNT ( 1 + 1 + 0 )
#define RUNTIME_FUNCTION_COUNT ( 1 + 1 + (0 * 2) )

#define PROVIDED_INTERFACE_COUNT ( 0 + 1 )

extern "C" {
#include <fero.h>
#include "partition_1_interface.h"
#include "transport.h"
#include "routing.h"
#include "thread_function1_trigger.h"
extern void init_function1(void);
void ardu_print(char* data);
}


FERO_SCHEDULER_BUFFER(scheduler_buffer, RUNTIME_TASK_COUNT);
Fero_Scheduler scheduler;

Fero_Tasklet function1_tasklet;

void create_tasklet_function1_trigger();
void create_tasklet_function1_trigger()
{
    Fero_Tasklet_init(
        &function1_tasklet,
        "function1_tasklet",
        function1_trigger_job,
        NULL
    );

    Fero_Scheduler_addTasklet(
        &scheduler,
        &function1_tasklet,
        0
    );

    Fero_TimeNs period = 1000 * 1000000;
    Fero_TimeNs offset = 0;

    Fero_Tasklet_setPeriodic(
        &function1_tasklet,
        period,
        offset
    );
}

void ardu_print(char* data)
{
    Serial.print(data);
}

void setup()
{
    Serial.begin(9600);
    initialize_transport();
    initialize_routing();

    Fero_Scheduler_init(
        &scheduler,
        RUNTIME_TASK_COUNT,
        scheduler_buffer
    );

    init_function1();

    create_tasklet_function1_trigger();
}


void loop()
{
    // Fero_TimeNs time = millis() * 1000000;
    // Workaround for millis not working on AVR Qemu
    static Fero_TimeNs time = 0;
    time += 1000000;
    Fero_Scheduler_invoke(&scheduler, time);
}