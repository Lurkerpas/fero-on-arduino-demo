#include "transport.h"

#include <rtems.h>

// Sporadic required

// Sporadic provided

#include "thread_corecomponent_tc.h"

#include <string.h>

void deliver_to_corecomponent_tc(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern rtems_id corecomponent_tc_Global_Queue;

    struct ThreadCorecomponent_TcRequest request = {0};
    if(length > 0)
    {
        memcpy(request.m_data, data, length);
    }
    request.m_length = length;
    request.m_sender_pid = (uint32_t)sender_pid;

    rtems_message_queue_send(corecomponent_tc_Global_Queue,
                             &request,
                             sizeof(struct ThreadCorecomponent_TcRequest ));
}


#include "thread_orchestratorcomponent_tm.h"

#include <string.h>

void deliver_to_orchestratorcomponent_tm(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern rtems_id orchestratorcomponent_tm_Global_Queue;

    struct ThreadOrchestratorcomponent_TmRequest request = {0};
    if(length > 0)
    {
        memcpy(request.m_data, data, length);
    }
    request.m_length = length;
    request.m_sender_pid = (uint32_t)sender_pid;

    rtems_message_queue_send(orchestratorcomponent_tm_Global_Queue,
                             &request,
                             sizeof(struct ThreadOrchestratorcomponent_TmRequest ));
}




void initialize_transport()
{
}
