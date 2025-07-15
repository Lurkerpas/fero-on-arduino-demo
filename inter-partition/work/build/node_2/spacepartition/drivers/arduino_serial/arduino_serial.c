#include "arduino_serial.h"

#include <assert.h>


void ArduinoSerialInit(
    void *private_data, const enum SystemBus bus_id,
    const enum SystemDevice device_id,
    const Arduino_Serial_Conf_T *const device_configuration,
    const Arduino_Serial_Conf_T *const remote_device_configuration)
{
}

void ArduinoSerialPoll(void *private_data) 
{
}

void ArduinoSerialSend(void *private_data, const uint8_t *const data, const size_t length)
{
}
