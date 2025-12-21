#include <iostream>
#include <stdexcept>

enum class RobotState {
    PoweredOff,
    Initializing,
    Ready,
    Active,
    Error
};


enum class FaultType {
    Minor,
    Major,
    Critical
};

struct PowerOnEvent {};
struct InitializationCompleteEvent {};
struct StartProcedureEvent {};
struct ResetEvent {};
struct FaultDetectedEvent { FaultType type;};


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

    void handleEvent(const PowerOnEvent&) {
        if (state == RobotState::PoweredOff) {
            state = RobotState::Initializing;
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const InitializationCompleteEvent&) {
        if (state == RobotState::Initializing) {
            state = RobotState::Ready;
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const StartProcedureEvent&) {
        if (state == RobotState::Ready) {
            state = RobotState::Active;
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const ResetEvent&) {
        if (state == RobotState::Error) {
            state = RobotState::PoweredOff;
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const FaultDetectedEvent& e) {
        if (state == RobotState::Active) {
            if (e.type == FaultType::Minor) {
                state = RobotState::Ready;
            } else {
                state = RobotState::Error;
            }
        } else {

        throw std::logic_error("Illegal event for current state");
    }
    }

    RobotState getState() const {
        return state;
    }
};

int main() {
    RobotController robot;

    try {
        robot.handleEvent(PowerOnEvent{});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(InitializationCompleteEvent{});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(StartProcedureEvent{});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(FaultDetectedEvent{FaultType::Minor});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(StartProcedureEvent{});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(FaultDetectedEvent{FaultType::Critical});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;

        robot.handleEvent(ResetEvent{});
        std::cout << "Current State: " << toString(robot.getState()) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "State machine error: " << e.what() << std::endl;
    }
    return 0;
}
