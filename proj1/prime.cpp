#include "prime.h"
#include <cmath>

using std::sqrt;

/// returns true if 'number' is prime
bool isPrime(uint32_t number) {
    auto doubleNumber = static_cast<double>(number);
    auto maximalDivider = static_cast<uint32_t>(sqrt(doubleNumber));
    for (uint32_t i = MINIMAL_DIVIDER; i <= maximalDivider; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

/** 
 * find 'count' primes and put them in 'output_array'
 * output_array [OUT] pointer to an unsigned integer array to put the results in.
 * count [IN] the number of primes to find.
 */
void find_primes(unsigned int output_array[], unsigned int count) {
    unsigned int current_count = 0;
    unsigned int current_number = MINIMAL_DIVIDER;

    while (current_count < count) {
        if (is_prime(current_number)) {
            output_array[current_count++] = current_number;
        }
        current_number++;
    }
}

