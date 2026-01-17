#ifndef FAKE_SENSOR_H
#define FAKE_SENSOR_H

#include "ISensor.h"

class FakeSensor  : public ISensor {
public:
    explicit FakeSensor(int value) : returnValue(value) {}
    int read() const override {
        return returnValue;
    }
private:
    int returnValue;
};  
#endif