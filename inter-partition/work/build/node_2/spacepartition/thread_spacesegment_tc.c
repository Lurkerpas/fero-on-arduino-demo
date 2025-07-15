#include "thread_spacesegment_tc.h"

#include <fero.h>
#include <assert.h>
#include "interfaces_info.h"

#include "spacepartition_interface.h"

extern Fero_Queue spacesegment_tc_queue;

bool spacesegment_tc_job(void* unused)
{
    struct ThreadSpacesegment_TcRequest request;
    uint32_t size;

    if (Fero_Queue_get(&spacesegment_tc_queue, &request, &size))
    {
        call_spacesegment_tc((const char*)request.m_data, size);
    }
}
