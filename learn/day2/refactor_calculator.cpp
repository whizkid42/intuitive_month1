#include <iostream>
#include <stdexcept>

enum class Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

struct Calculator {
    const Operation operation;

    explicit Calculator(Operation op) : operation(op) {
        // no runtime validation required for a strongly-typed enum
    }

    int calculate(int a, int b) const {
        switch (operation) {
            case Operation::ADD:      return a + b;
            case Operation::SUBTRACT: return a - b;
            case Operation::MULTIPLY: return a * b;
            case Operation::DIVIDE:
                if (b == 0) {
                    throw std::invalid_argument("Division by zero is not allowed.");
                }
                return a / b;
        }
        throw std::invalid_argument("Invalid operation.");
    }
};

int main() {
    try {
        Calculator addCalc(Operation::ADD);
        std::cout << "Add: " << addCalc.calculate(10, 5) << std::endl;

        Calculator subCalc(Operation::SUBTRACT);
        std::cout << "Subtract: " << subCalc.calculate(10, 5) << std::endl;

        Calculator mulCalc(Operation::MULTIPLY);
        std::cout << "Multiply: " << mulCalc.calculate(10, 5) << std::endl;

        Calculator divCalc(Operation::DIVIDE);
        std::cout << "Divide: " << divCalc.calculate(10, 0) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}