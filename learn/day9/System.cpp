#include "System.h"
#include "Logger.h"

System::System() 
    : sensor(std::make_unique<Sensor>()), 
      actuator(std::make_unique<Actuator>()),
      controller(*sensor, *actuator) {

    Logger::log(LogLevel::INFO, "System", "System initialized successfully!");


    }
void System::runOnce() {
    controller.update();
}