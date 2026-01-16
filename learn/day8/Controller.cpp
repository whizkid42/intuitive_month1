#include "Controller.h"

Controller::Controller(const Sensor& sensor, Actuator& actuator)
    : sensor(sensor), actuator(actuator) {}

void Controller::update() {
    int sensorValue = sensor.read();
    actuator.command(sensorValue * 2);
}