#include <iostream>

void print(const int& x) {
    std::cout << x << std::endl;
}

int main() {
    const int a = 10;
    print(a);
}