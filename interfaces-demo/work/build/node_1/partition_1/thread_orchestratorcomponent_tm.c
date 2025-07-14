#include "thread_orchestratorcomponent_tm.h"

#include <assert.h>
#include "interfaces_info.h"

#include "partition_1_interface.h"

extern Fero_Queue orchestratorcomponent_tm_queue;

bool orchestratorcomponent_tm_job(void* unused)
{
    ThreadOrchestratorcomponent_TmRequest request;
    uint32_t size;

    if (Fero_Queue_get(&orchestratorcomponent_tm_queue, &request, &size))
    {
        call_orchestratorcomponent_tm((const char*)request.m_data, size);
    }
}
