#ifndef FAKE_SENSOR_H
#define FAKE_SENSOR_H

#include "ISensor.h"

class FakeSensor  : public ISensor {
public:
    FakeSensor(int value, SensorStatus status) : returnValue(value), sensorStatus(status) {}
    int read() const override {
        return returnValue;
    }
    SensorStatus status() const override {
        return sensorStatus;
    }
private:
    int returnValue;
    SensorStatus sensorStatus;
};  
#endif