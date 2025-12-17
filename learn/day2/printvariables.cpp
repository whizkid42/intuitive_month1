#include <iostream>

int main() {
    int joints = 6;
    double velocity = 0.25;

    std::cout << "Number of joints:" << joints <<std:: endl;
    std::cout << "Velocity (m/s):" << velocity << std::endl;

    std::cout << sizeof(joints) << std::endl;
    std::cout << sizeof(velocity) << std::endl;
    return 0;
}