#include "Controller.h" 
#include "FakeSensor.h"
#include "FakeActuator.h"
#include <cassert>

int main() {
    {
        FakeSensor sensor(10);
        FakeActuator actuator;
        Controller controller(sensor, actuator);
        controller.update();
        assert(actuator.wasCalled);
        assert(actuator.lastValue == 20);
    }
    {
        FakeSensor sensor(-10);
        FakeActuator actuator;
        Controller controller(sensor, actuator);
        controller.update();
        assert(!actuator.wasCalled);
    }
    {
        FakeSensor sensor(150);
        FakeActuator actuator;
        Controller controller(sensor, actuator);
        controller.update();
        assert(!actuator.wasCalled);
    }
    return 0;
}