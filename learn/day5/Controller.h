#ifndef CONTROLLER_H    
#define CONTROLLER_H
#include "Sensor.h"

class Controller {
public:
    Controller(const Sensor& sensor);
    void printSensorValue() const;

private:
    const Sensor& sensor;

};

#endif