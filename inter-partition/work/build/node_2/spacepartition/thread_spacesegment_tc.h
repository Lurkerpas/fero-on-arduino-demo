#ifndef spacesegment_tc_INCLUDED
#define spacesegment_tc_INCLUDED

#include <stdint.h>

#include "request_size.h"
#include <dataview-uniq.h>
#include <routing.h>

struct ThreadSpacesegment_TcRequest
{
    uint8_t m_data[SPACESEGMENT_TC_REQUEST_SIZE];
};

bool spacesegment_tc_job(void* unused);

#endif // spacesegment_tc_INCLUDED
