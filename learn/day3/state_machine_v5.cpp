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
    int tickInState;

    static constexpr int INIT_TIMEOUT = 5;
    static constexpr int ACTIVE_TIMEOUT = 3;

    void changeState(RobotState newState) {
    state = newState;
    tickInState = 0;
    }

public:
    RobotController()
        : state(RobotState::PoweredOff),
          tickInState(0) {}

    void tick() {
        tickInState++;

        if (state == RobotState::Initializing &&
            tickInState > INIT_TIMEOUT) {
            changeState(RobotState::Error);
        }

        if (state == RobotState::Active &&
            tickInState > ACTIVE_TIMEOUT) {
            changeState(RobotState::Error);
        }
    }

    void handleEvent(const PowerOnEvent&) {
        if (state == RobotState::PoweredOff) {
           changeState(RobotState::Initializing);
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const InitializationCompleteEvent&) {
        if (state == RobotState::Initializing) {
            changeState(RobotState::Ready);
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const StartProcedureEvent&) {
        if (state == RobotState::Ready) {
            changeState(RobotState::Active);
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const ResetEvent&) {
        if (state == RobotState::Error) {
            changeState(RobotState::PoweredOff);
        } else {
            throw std::logic_error("Illegal event for current state");
        }
    }

    void handleEvent(const FaultDetectedEvent& e) {
        if (state == RobotState::Active) {
            tickInState = 0;
            if (e.type == FaultType::Minor) {
                changeState(RobotState::Ready);
            } else {
                changeState(RobotState::Error);
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

    robot.handleEvent(PowerOnEvent{});

    for (int i = 0; i < 6; ++i) {
        robot.tick();
    }

    std::cout << "State after init timeout: "
              << toString(robot.getState()) << std::endl;
}
