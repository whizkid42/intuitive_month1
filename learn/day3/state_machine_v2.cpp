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

    void onEvent(RobotEvent event) {
        if(state == RobotState::PoweredOff && event == RobotEvent::PowerOn) {
            state = RobotState::Initializing;
        } else if (state == RobotState::Initializing && event == RobotEvent::InitializationComplete) {
            state = RobotState::Ready;
        } else if (state == RobotState::Ready && event == RobotEvent::StartProcedure) {
            state = RobotState::Active;
        } else if (state == RobotState::Active && event == RobotEvent::FaultDetected) {
            state = RobotState::Error;
        } else if (state == RobotState::Error && event == RobotEvent::Reset) {
            state = RobotState::PoweredOff;
        } else {
            throw std::logic_error(
                std::string("Event ") 
                + std::to_string(static_cast<int>(event))
                + " is invalid in state "
                + toString(state)
            );
        }
    }
    RobotState getState() const {
        return state;
    }
};

int main() {
    RobotController robot;

    try {
        robot.onEvent(RobotEvent::PowerOn);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.onEvent(RobotEvent::InitializationComplete);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.onEvent(RobotEvent::StartProcedure);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.onEvent(RobotEvent::FaultDetected);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.onEvent(RobotEvent::Reset);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        // This will throw an exception
        robot.onEvent(RobotEvent::FaultDetected);
    } catch (const std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}