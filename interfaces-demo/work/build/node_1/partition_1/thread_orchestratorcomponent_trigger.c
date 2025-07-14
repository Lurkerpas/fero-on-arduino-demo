#include "thread_orchestratorcomponent_trigger.h"

#include <fero.h>
#include <assert.h>
#include "interfaces_info.h"

#include "partition_1_interface.h"

bool orchestratorcomponent_trigger_job(void* unused)
{
    call_orchestratorcomponent_trigger(NULL, 0);
}
