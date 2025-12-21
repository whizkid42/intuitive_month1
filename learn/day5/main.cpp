#include "Sensor.h"
#include "Controller.h"

int main() {
    Sensor sensor;
    Controller controller(sensor);

    controller.printSensorValue();
    return 0;
}
