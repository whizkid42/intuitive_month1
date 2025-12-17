#include <iostream>
#include <stdexcept>
using namespace std;

enum class Operation {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE
};

    struct Calculator {
        Operation operation;

        explicit Calculator(Operation op) : operation(op) {}

        int calculate(int a, int b) {
            switch (operation) {
                case Operation::ADD:
                    return a + b;
                case Operation::SUBTRACT:
                    return a - b;
                case Operation::MULTIPLY:
                    return a * b;
                case Operation::DIVIDE:
                    if (b == 0) {
                        throw invalid_argument("Division by zero is not allowed.");
                    }
                    return a / b;
                default:
                    throw invalid_argument("Invalid operation.");
            }
        }
    };

int main() {
        Calculator addCalc(Operation::ADD);
        cout << "Add: " << addCalc.calculate(10, 5) << endl;

        Calculator subCalc(Operation::SUBTRACT);
        cout << "Subtract: " << subCalc.calculate(10, 5) << endl;

        Calculator mulCalc(Operation::MULTIPLY);
        cout << "Multiply: " << mulCalc.calculate(10, 5) << endl;

        Calculator divCalc(Operation::DIVIDE);
        cout << "Divide: " << divCalc.calculate(10, 5) << endl; // This will throw an exception
    

    return 0;
}
    

