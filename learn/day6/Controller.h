#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Sensor.h"
#include "Actuator.h"

class Controller {
public:
    Controller(const Sensor& sensor, Actuator& actuator);
    void update();

private:
    const Sensor& sensor;
    Actuator& actuator;
};  

#endif