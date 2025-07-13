#ifndef corecomponent_tc_INCLUDED
#define corecomponent_tc_INCLUDED

#include <stdint.h>
#include <rtems.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadCorecomponent_TcRequest
{
    uint32_t m_sender_pid;
    uint32_t m_length;
    uint8_t m_data[CORECOMPONENT_TC_REQUEST_SIZE] __attribute__((aligned(16)));
};

rtems_task corecomponent_tc_job(rtems_task_argument unused);

#endif // corecomponent_tc_INCLUDED
