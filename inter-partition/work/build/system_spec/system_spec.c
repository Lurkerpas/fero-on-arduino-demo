#include "system_spec.h"

#include <drivers_config.h>

enum SystemBus port_to_bus_map[] = {
    BUS_INVALID_ID,
	BUS_BUS_1,
};

enum RemoteInterface bus_to_port_map[] = {
	INTERFACE_INVALID_ID,
	INTERFACE_GROUNDSEGMENT_TM,
	INTERFACE_SPACESEGMENT_TC,
};

struct PartitionBusPair port_to_partition_bus_map[] = {
    { PARTITION_INVALID_ID, BUS_INVALID_ID },
    { SPACEPARTITION, BUS_BUS_1 },
    { GROUNDPARTITION, BUS_BUS_1 },
};

enum SystemBus device_to_bus_map[SYSTEM_DEVICE_NUMBER] = {
    BUS_BUS_1,
};

const void* const device_configurations[SYSTEM_DEVICE_NUMBER] = {
    &pohidrv_node_2_uart0,
};

const unsigned packetizer_configurations[SYSTEM_DEVICE_NUMBER] = {
    PACKETIZER_DEFAULT,
};
