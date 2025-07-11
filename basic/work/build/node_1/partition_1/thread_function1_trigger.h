#ifndef function1_trigger_INCLUDED
#define function1_trigger_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadFunction1_TriggerRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[FUNCTION1_TRIGGER_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task function1_trigger_job(rtems_task_argument unused);

#endif // function1_trigger_INCLUDED
