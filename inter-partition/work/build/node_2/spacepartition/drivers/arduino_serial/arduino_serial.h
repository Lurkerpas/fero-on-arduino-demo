#pragma once

#include <assert.h>

#include <Broker.h>
#include <Escaper.h>

#include <drivers_config.h>


#define ARDUINO_SERIAL_TASKLET_PRIORITY 64
#define ARDUINO_SERIAL_BUFFER_SIZE 16
#define ARDUINO_SERIAL_ENCODED_PACKET_MAX_SIZE BROKER_BUFFER_SIZE
#define ARDUINO_SERIAL_DECODED_PACKET_MAX_SIZE BROKER_BUFFER_SIZE

typedef struct final {
  
} arduino_serial_private_data;


void ArduinoSerialInit(
    void *private_data, const enum SystemBus bus_id,
    const enum SystemDevice device_id,
    const Arduino_Serial_Conf_T *const device_configuration,
    const Arduino_Serial_Conf_T *const remote_device_configuration);

void ArduinoSerialPoll(void *private_data);

void ArduinoSerialSend(void *private_data, const uint8_t *const data, const size_t length);
