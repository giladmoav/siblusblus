#include "prime.h"
#include <cmath>

/// returns true if 'number' is prime
bool isPrime(unsigned int number) {
    double doubleNumber = static_cast<double>(number);
    unsigned int maximalDivider = static_cast<unsigned int>(std::sqrt(doubleNumber));
    for (unsigned int i = MINIMAL_DIVIDER; i <= maximalDivider; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
