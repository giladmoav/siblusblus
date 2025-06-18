#include "prime.h"
#include <iostream>

using std::cout;
using std::endl;

/// prints 'count' unsigned int elements of 'array'
void printArray(unsigned int array[], unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        cout << i << ": " << array[i] << endl;
    }
}

int main() {
    const unsigned int arrayLength = 5;
    unsigned int array[arrayLength];
    findPrimes(array, arrayLength);
    printArray(array, arrayLength);
}

