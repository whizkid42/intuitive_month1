#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include "Controller.h"
#include "Sensor.h"
#include "Actuator.h"

class System {
public:
    System();
    void runOnce();

private:
    std::unique_ptr<Sensor> sensor;
    std::unique_ptr<Actuator> actuator;
    Controller controller;
};

#endif