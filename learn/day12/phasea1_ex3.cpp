
#include <iostream>

bool validateTrajectory(
    const int positions[],
    int size,
    int min,
    int max
) {
    if (size <= 1) {
        return true;
    }
    for (int i=0; i < size ; i++) {
        if(i>0 && positions[i] < positions[i-1]) {
            return false;
        }
        if (positions[i] < min || positions[i] > max) {
            return false;
        }
    }
    return true;
}

int main() {
    const int trajectory[] = { 0, 5, 100,15, 20 }; // Sample trajectory
    bool isValid = validateTrajectory(trajectory, 5, 0, 20);

    std::cout << "Trajectory is " << (isValid ? "valid" : "invalid") << std::endl;

    return 0;
}