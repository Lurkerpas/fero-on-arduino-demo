#include "thread_function1_trigger.h"

#include "partition_1_interface.h"


bool function1_trigger_job(void* unused)
{
    call_function1_trigger(NULL, 0);
}
