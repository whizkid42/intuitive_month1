#include <iostream>

int main() {
    // Print numbers from 1 to 10 using a loop
    for (int i = 10; i >= 1; --i) {
        std::cout << i << std::endl;
    }

    //Print a square of stars(5x5)
    for (int i=0; i<5;++i) {
        for (int j=0;j<5;++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    //Print name 5 times
    for (int i=0;i<5;++i) {
        std::cout << "Dev" << std::endl;
    }

    return 0;
}


