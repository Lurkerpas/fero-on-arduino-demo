#include "thread_corecomponent_tc.h"

#include <assert.h>
#include "interfaces_info.h"

#include "partition_1_interface.h"

extern Fero_Queue corecomponent_tc_queue;

bool corecomponent_tc_job(void* unused)
{
    ThreadCorecomponent_TcRequest request;
    uint32_t size;

    if (Fero_Queue_get(&corecomponent_tc_queue, &request, &size))
    {
        call_corecomponent_tc((const char*)request.m_data, size);
    }
}
