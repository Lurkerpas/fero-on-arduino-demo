#ifndef orchestratorcomponent_trigger_INCLUDED
#define orchestratorcomponent_trigger_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadOrchestratorcomponent_TriggerRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[ORCHESTRATORCOMPONENT_TRIGGER_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task orchestratorcomponent_trigger_job(rtems_task_argument unused);

#endif // orchestratorcomponent_trigger_INCLUDED
