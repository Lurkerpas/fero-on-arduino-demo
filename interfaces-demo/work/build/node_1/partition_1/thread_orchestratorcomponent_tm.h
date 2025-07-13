#ifndef orchestratorcomponent_tm_INCLUDED
#define orchestratorcomponent_tm_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadOrchestratorcomponent_TmRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[ORCHESTRATORCOMPONENT_TM_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task orchestratorcomponent_tm_job(rtems_task_argument unused);

#endif // orchestratorcomponent_tm_INCLUDED
