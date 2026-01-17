#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "IActuator.h"

class Actuator : public IActuator {
public:
    void command(int value);
};

#endif