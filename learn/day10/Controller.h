#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ISensor.h"
#include "IActuator.h"

class Controller {
public:
    Controller(const ISensor& sensor, IActuator& actuator);
    void update();

private:
    const ISensor& sensor;
    IActuator& actuator;
};  

#endif