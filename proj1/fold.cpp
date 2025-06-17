
#include <iostream>

constexpr int BOARD_SIZE = 11;

void main() {

    // print columns' headers
    for (int i = 1; i <= BOARD_SIZE; i++) {
        std::cout << "\t" << i;
    }
    std::cout << std::endl;

    // print rows
    for (int i = 1; i <= BOARD_SIZE; i++) {
        std::cout << i;
        for (int j = 1; j <= BOARD_SIZE; j++) {
            std::cout << "\t" << i * j;
        }
        std::cout << std::endl;
    }
}
