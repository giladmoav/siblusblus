#include "prime.h"
#include <iostream>

using std::cout;
using std::endl;

void print_array(unsigned int array[], unsigned int count) {
    for (int i = 0; i < count; i++) {
        cout << i << ": " << array[i] << endl;
    }
}

int main() {
    unsigned int array[5];
    find_primes(array, 5);
    print_array(array, 5);
}

