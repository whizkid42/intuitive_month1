#include <iostream>

 int clampAndCount(
    const int values[],
    int size,
    int min,
    int max,
    int& clampCount
) {
    clampCount = 0;
    int sum = 0;

    for (int i=0; i< size; i++) {
        int clampedValue = values[i];

        if (values[i] < min) {
            clampedValue = min;
            clampCount++;
        } else if (values[i] > max) {
            clampedValue = max;
            clampCount++;
        }
        sum += clampedValue;
    }
    return sum;
}

int main() {
    const int data[] = { -5, 10, 15, 25, 30 }; // Sample data
    int clampCount = 0;
    int sum = clampAndCount(data, 5, 0, 20, clampCount);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Clamped Values Count: " << clampCount << std::endl;

    return 0;
}

