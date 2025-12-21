#include "Sensor.h"
#include "Controller.h"
#include "Actuator.h"

int main() {
    Sensor sensor;
    Actuator actuator;
    Controller controller(sensor, actuator);

    controller.update();
    return 0;
}