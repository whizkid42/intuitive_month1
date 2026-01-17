#include "Sensor.h"

Sensor::Sensor() : value(25) {}

int Sensor::read() const {
    return value;
}

