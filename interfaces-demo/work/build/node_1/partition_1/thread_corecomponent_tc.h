#ifndef corecomponent_tc_INCLUDED
#define corecomponent_tc_INCLUDED

#include <stdint.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadCorecomponent_TcRequest
{
    uint8_t m_data[CORECOMPONENT_TC_REQUEST_SIZE];
};

bool corecomponent_tc_job(void* unused);

#endif // corecomponent_tc_INCLUDED
