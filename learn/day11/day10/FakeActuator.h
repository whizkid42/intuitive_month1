#ifndef FAKE_ACTUATOR_H
#define FAKE_ACTUATOR_H

#include "IActuator.h"

class FakeActuator : public IActuator {
public:
    void command(int value) override {
        wasCalled = true;
        lastValue = value;
    }
    bool wasCalled = false;
    int lastValue = 0;
};          

#endif 