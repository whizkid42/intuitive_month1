#include <stdexcept>
#include <iostream> 



enum class RobotState {
    PoweredOff,
    Initializing,
    Ready,
    Active,
    Error
};

enum class RobotEvent {
    PowerOn,
    InitializationComplete,
    StartProcedure,
    FaultDetected,
    Reset
};
struct Transition {
    RobotState from;
    RobotEvent event;
    RobotState to;
};

const Transition transitions[] = {
    {RobotState::PoweredOff, RobotEvent::PowerOn, RobotState::Initializing},
    {RobotState::Initializing, RobotEvent::InitializationComplete, RobotState::Ready},
    {RobotState::Ready, RobotEvent::StartProcedure, RobotState::Active},
    {RobotState::Active, RobotEvent::FaultDetected, RobotState::Error},
    {RobotState::Error, RobotEvent::Reset, RobotState::PoweredOff}
};

const char* toString(RobotState state) {
    switch (state) {
        case RobotState::PoweredOff:   return "PoweredOff";
        case RobotState::Initializing: return "Initializing";
        case RobotState::Ready:        return "Ready";
        case RobotState::Active:       return "Active";
        case RobotState::Error:        return "Error";
    }
    return "Unknown";
}



struct RobotController {
private:
    RobotState state;

public:
    RobotController()
        : state(RobotState::PoweredOff) {}

    void handleEvent(RobotEvent event) {
        for (const auto& t : transitions) {
            if (t.from == state && t.event == event) {
                state = t.to;
                return;
            }
        }

        throw std::logic_error("Illegal event for current state");
    }

    RobotState getState() const {
        return state;
    }
};



int main() {
    RobotController robot;

    try {
        robot.handleEvent(RobotEvent::PowerOn);
        std::cout << toString(robot.getState()) << std::endl;

        robot.handleEvent(RobotEvent::InitializationComplete);
        std::cout << toString(robot.getState()) << std::endl;

        robot.handleEvent(RobotEvent::StartProcedure);
        std::cout << toString(robot.getState()) << std::endl;

        robot.handleEvent(RobotEvent::FaultDetected);
        std::cout << toString(robot.getState()) << std::endl;

        robot.handleEvent(RobotEvent::Reset);
        std::cout << toString(robot.getState()) << std::endl;

        // Illegal event
        robot.handleEvent(RobotEvent::StartProcedure);
    }
    catch (const std::exception& e) {
        std::cerr << "State machine error: " << e.what() << std::endl;
    }
    return 0;
}