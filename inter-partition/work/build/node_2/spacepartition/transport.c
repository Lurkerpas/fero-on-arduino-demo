#include "transport.h"
#include <fero.h>

// Sporadic required
void deliver_to_groundsegment_tm(
   const asn1SccPID sender_pid,
   const uint8_t* const data,
   const size_t length)
{
    Broker_deliver_request(
            INTERFACE_GROUNDSEGMENT_TM,
            data,
            length);
}

// Sporadic provided

#include "thread_spacesegment_tc.h"

#include <string.h>

void deliver_to_spacesegment_tc(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length)
{
    extern Fero_Queue spacesegment_tc_queue;

    struct ThreadSpacesegment_TcRequest request = {0};
    if(length > 0)
    {
        memcpy(request.m_data, data, length);
    }

    Fero_Queue_put(&spacesegment_tc_queue,
                    &request,
                    sizeof(struct ThreadSpacesegment_TcRequest ));
}


void initialize_transport()
{
    interface_to_deliver_function[INTERFACE_SPACESEGMENT_TC] = &deliver_to_spacesegment_tc;
}
