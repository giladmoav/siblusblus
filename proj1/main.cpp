#include "prime.h"
#include <iostream>

using std::cout;
using std::endl;

/// prints 'count' unsigned int elements of 'array'
void printArray(uint32_t array[], uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        cout << i << ": " << array[i] << endl;
    }
}

int main() {
    const uint32_t arrayLength = 5;
    uint32_t array[arrayLength];
    findPrimes(array, arrayLength);
    printArray(array, arrayLength);
}

