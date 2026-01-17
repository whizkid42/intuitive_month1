#include "Sensor.h"

Sensor::Sensor() : value(25) {}

int Sensor::read() const {
    return value;
}

SensorStatus Sensor::status() const {
    return SensorStatus::OK;
}

