#include <iostream>
#include <stdexcept>

struct RobotConfig {
    int id;
    double max_velocity;

    explicit RobotConfig(int robot_id, double max_vel) 
        : id(robot_id), max_velocity(max_vel) {
            if (max_velocity < 0.0) {
                throw std::invalid_argument("max_velocity must be non-negative");
            }
        }
};

int main() {
    try {
        RobotConfig robot1(1, 2.5);
        std::cout << "Robot ID: " << robot1.id << ", Max Velocity: " << robot1.max_velocity << std::endl;

        RobotConfig robot2(2, -3.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error creating RobotConfig: " << e.what() << std::endl;
    }

    return 0;
}