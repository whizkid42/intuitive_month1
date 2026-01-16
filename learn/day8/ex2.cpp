#include "ex2.h"

System::System()
    : sensor(std::make_unique<Sensor>()) {}

void System::update() {
    int sensorValue = sensor->read();

}