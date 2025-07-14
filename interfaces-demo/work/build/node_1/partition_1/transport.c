#include "transport.h"

// Sporadic required

// Sporadic provided

#include "thread_corecomponent_tc.h"

#include <string.h>

void deliver_to_corecomponent_tc(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern Fero_Queue corecomponent_tc_queue;

    Fero_Queue_put(
        &corecomponent_tc_queue,
        data,
        length
    );
}


#include "thread_orchestratorcomponent_tm.h"

#include <string.h>

void deliver_to_orchestratorcomponent_tm(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern Fero_Queue orchestratorcomponent_tm_queue;

    Fero_Queue_put(
        &orchestratorcomponent_tm_queue,
        data,
        length
    );
}




void initialize_transport()
{
}
