#include <stdexcept>
#include <iostream>
#include <string>

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
    private:
    RobotState state;
    
    public:
    RobotController()
        : state(RobotState::PoweredOff) {}
    
    void requestTransition(RobotState requestedState) {
        if (state == RobotState::PoweredOff && requestedState == RobotState::Initializing) {
            state = requestedState;
        } else if (state == RobotState::Initializing && requestedState == RobotState::Ready) {
            state = requestedState;
        } else if (state == RobotState::Ready && requestedState == RobotState::Active) {
            state = requestedState;
        } else if (state == RobotState::Active && requestedState == RobotState::Error) {
            state = requestedState;
        } else if (state == RobotState::Error && requestedState == RobotState::PoweredOff) {
            state = requestedState;
        } else {
            throw std::logic_error(
                std::string("Illegal transition from ") + toString(state) + " to " + toString(requestedState)
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
        robot.requestTransition(RobotState::Initializing);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.requestTransition(RobotState::Ready);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.requestTransition(RobotState::Active);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.requestTransition(RobotState::Error);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        robot.requestTransition(RobotState::PoweredOff);
        std::cout << "Current state: " << toString(robot.getState()) << std::endl;

        // This will throw an exception
        robot.requestTransition(RobotState::Active);
    } catch (const std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
