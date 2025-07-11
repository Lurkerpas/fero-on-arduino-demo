#include "system_spec.h"


enum SystemBus port_to_bus_map[] = {
    BUS_INVALID_ID,
};

enum RemoteInterface bus_to_port_map[] = {
	INTERFACE_INVALID_ID,
};

struct PartitionBusPair port_to_partition_bus_map[] = {
    { PARTITION_INVALID_ID, BUS_INVALID_ID },
};

enum SystemBus device_to_bus_map[SYSTEM_DEVICE_NUMBER] = {
};

const void* const device_configurations[SYSTEM_DEVICE_NUMBER] = {
};

const unsigned packetizer_configurations[SYSTEM_DEVICE_NUMBER] = {
};
