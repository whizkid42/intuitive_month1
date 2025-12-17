#include <stdexcept>
#include <iostream>

struct MotorController {
    int motor_id;

    explicit MotorController(int id)
        : motor_id(id) {
            if(motor_id < 0) {  // id < 0 is better to use
                throw std::invalid_argument("motor_id must be non-negative");
            }
        }
};

int main() {
    try {
        MotorController motor1(5);
        MotorController motor2(-3); // This will throw an exception
    } catch (const std::invalid_argument& e) { // std::exception is better
        std::cerr << "Error creating MotorController: " << e.what() << std::endl;
    }

    return 0;
}