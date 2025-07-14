#ifndef orchestratorcomponent_tm_INCLUDED
#define orchestratorcomponent_tm_INCLUDED

#include <stdint.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadOrchestratorcomponent_TmRequest
{
    uint8_t m_data[ORCHESTRATORCOMPONENT_TM_REQUEST_SIZE];
};

bool orchestratorcomponent_tm_job(void* unused);

#endif // orchestratorcomponent_tm_INCLUDED
