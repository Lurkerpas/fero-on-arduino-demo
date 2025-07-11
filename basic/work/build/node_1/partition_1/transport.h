#ifndef GENERIC_RTEMS6_TRANSPORT_H
#define GENERIC_RTEMS6_TRANSPORT_H

#include <stdint.h>

#include <system_spec.h>

#include <Broker.h>
#include <request_size.h>
#include <dataview-uniq.h>

void initialize_transport();

// Sporadic required

// Sporadic provided
void deliver_to_function1_trigger(const asn1SccPID sender_pid, const uint8_t* const data, const size_t length);

extern deliver_function interface_to_deliver_function[INTERFACE_MAX_ID];

#endif
