#include "Actuator.h"
#include <iostream>

void Actuator::command(int value) {
    std::cout << "Commanding actuator with value: " << value << std::endl;
}