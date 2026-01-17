#include "Controller.h"
#include "Logger.h"
#include <string>

Controller::Controller(const ISensor& sensor, IActuator& actuator)
    : sensor(sensor), actuator(actuator) {}

void Controller::update() {
    if (sensor.status() != SensorStatus::OK) {
        Logger::log(LogLevel::ERROR, "Controller", "Sensor failure detected - motion inhibited");
        return;
    }
    int sensorValue = sensor.read();
    Logger::log(LogLevel::INFO, "Controller", "Sensor value read: " + std::to_string(sensorValue));

    if (sensorValue < 0 || sensorValue > 100) {
        Logger::log(LogLevel::WARN, "Controller", "Sensor value outside safe range");
        return;
    }
    actuator.command(sensorValue *2);

}
