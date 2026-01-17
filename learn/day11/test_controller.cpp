#include "Controller.h" 
#include "FakeSensor.h"
#include "FakeActuator.h"
#include "SensorStatus.h"
#include <cassert>

int main() {
    {
        FakeSensor staleSensor(10, SensorStatus::STATLE);
        FakeActuator actuator;
        Controller controller(staleSensor, actuator);
        controller.update();
        assert(!actuator.wasCalled);
    }
    {
        FakeSensor failedSensor(0, SensorStatus::FAILED);
        FakeActuator actuator;
        Controller controller(failedSensor, actuator);
        controller.update();
        assert(!actuator.wasCalled);
    }
    // Test: valid sensor value commands actuator
    {
        FakeSensor okSensor(30, SensorStatus::OK);
        FakeActuator actuator;
        Controller controller(okSensor, actuator);

        controller.update();

        assert(actuator.wasCalled);
        assert(actuator.lastValue == 60); // 30 * 2
    }


    return 0;
}