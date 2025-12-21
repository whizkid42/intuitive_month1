#include "Sensor.h"

Sensor::Sensor() : value() {}
int Sensor::readValue() const {
    return value;
}