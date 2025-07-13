#ifndef REQUEST_SIZE_H
#define REQUEST_SIZE_H

#include <stdint.h>

#include "dataview-uniq.h"

// struct used to calculate buffer size for drivers
struct GenericRtems6AllParametersStub
{
    union
    {
        // input ports

        // output ports

        uint8_t dummy_union_field[1];
    } all_types;
};

// GENERIC_PARTITION_BUFFER_SIZE should be even number
#define GENERIC_PARTITION_BUFFER_SIZE (((sizeof(struct GenericRtems6AllParametersStub) + 1) / 2) * 2)


#define CORECOMPONENT_TC_REQUEST_SIZE (asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING)

#define ORCHESTRATORCOMPONENT_TM_REQUEST_SIZE (asn1SccTestStruct_REQUIRED_BYTES_FOR_ACN_ENCODING)

#define ORCHESTRATORCOMPONENT_TRIGGER_REQUEST_SIZE (1)


#endif
