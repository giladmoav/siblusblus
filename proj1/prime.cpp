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
