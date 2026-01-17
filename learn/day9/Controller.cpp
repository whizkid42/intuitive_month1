#include "Controller.h"
#include "Logger.h"
#include <string>

Controller::Controller(const Sensor& sensor, Actuator& actuator)
    : sensor(sensor), actuator(actuator) {}

void Controller::update() {
    int sensorValue = sensor.read();
    Logger::log(LogLevel::INFO, "Controller", "Sensor value read: " + std::to_string(sensorValue));

    if (sensorValue < 0) {
        Logger::log(LogLevel::WARN, "Controller", "Sensor value is negative");
        return;
    } else if (sensorValue > 100) {
        Logger::log(LogLevel::ERROR, "Controller", "Sensor value exceeds maximum threshold");
        return;
    }
    actuator.command(sensorValue *2);

}
