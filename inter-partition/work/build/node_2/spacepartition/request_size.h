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
        uint8_t spacesegment_tc[asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING];

        // output ports
        uint8_t SpaceSegment_tm_GroundSegment_tm[asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING];

        uint8_t dummy_union_field[1];
    } all_types;
};

// GENERIC_PARTITION_BUFFER_SIZE should be even number
#define GENERIC_PARTITION_BUFFER_SIZE (((sizeof(struct GenericRtems6AllParametersStub) + 1) / 2) * 2)


#define SPACESEGMENT_TC_REQUEST_SIZE (asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING)

#define GROUNDSEGMENT_GROUNDSEGMENT_TM_REQUEST_SIZE (asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING)

#endif
