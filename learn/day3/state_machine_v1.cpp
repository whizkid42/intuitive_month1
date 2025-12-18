#include <stdexcept>
#include <iostream>

enum class RobotState {
    PoweredOff,
    Initializing,
    Ready,
    Active,
    Error
};

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

};

int main() {
    RobotController robot;

    try {
        robot.transitionTo(RobotState::Initializing);
        std::cout << "Transitioned to Initializing" << std::endl;

        robot.transitionTo(RobotState::Ready);
        std::cout << "Transitioned to Ready" << std::endl;

        robot.transitionTo(RobotState::Active);
        std::cout << "Transitioned to Active" << std::endl;

        robot.transitionTo(RobotState::Error);
        std::cout << "Transitioned to Error" << std::endl;

        robot.transitionTo(RobotState::PoweredOff);
        std::cout << "Transitioned to PoweredOff" << std::endl;

        // This will throw an exception
        robot.transitionTo(RobotState::Active);
    } catch (const std::logic_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
