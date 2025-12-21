#include "Controller.h"
#include <iostream>

Controller::Controller(const Sensor& sensor) : sensor(sensor) {}

void Controller::printSensorValue() const {
    std::cout << "Sensor Value: " << sensor.readValue() << std::endl;
}