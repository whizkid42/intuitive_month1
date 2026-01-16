#include "System.h"

System::System()
    : sensor(std::make_unique<Sensor>()),
      actuator(std::make_unique<Actuator>()),
      controller(*sensor, *actuator) {}


void System::runOnce() {
    controller.update();
}