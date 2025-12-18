#include <stdexcept>
#include <iostream>

enum class RobotState {
    PoweredOff,
    Initializing,
    Ready,
    Active,
    Error
};

const char* toString(RobotState state) {
        switch (state) {
            case RobotState::PoweredOff:   return "PoweredOff";
            case RobotState::Initializing:  return "Initializing";
            case RobotState::Ready:         return "Ready";
            case RobotState::Active:        return "Active";
            case RobotState::Error:         return "Error";
            default:                        return "Unknown";
        }
}

struct RobotController {
    RobotState state;

    RobotController()
        : state(RobotState::PoweredOff) {}
    
    void transitionTo(RobotState newState) {
        if (state == RobotState::PoweredOff && newState == RobotState::Initializing) {
            state = newState;
        } else if (state == RobotState::Initializing && newState == RobotState::Ready) {
            state = newState;
        } else if (state == RobotState::Ready && newState == RobotState::Active) {
            state = newState;
        } else if (state == RobotState::Active && newState == RobotState::Error) {
            state = newState;
        } else if (state == RobotState::Error && newState == RobotState::PoweredOff) {
            state = newState;
        } else {
            throw std::logic_error("Invalid state transition.");
        }
    }

    RobotState getState() const {
        return state;
    }


};

int main() {
    RobotController robot;

    try {
        robot.transitionTo(RobotState::Initializing);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.transitionTo(RobotState::Ready);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.transitionTo(RobotState::Active);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.transitionTo(RobotState::Error);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.transitionTo(RobotState::PoweredOff);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        // This will throw an exception
        robot.transitionTo(RobotState::Active);
    } catch (const std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
