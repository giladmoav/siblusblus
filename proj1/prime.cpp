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
 * find 'count' primes and put them in 'outputArray'
 * outputArray [OUT] pointer to an unsigned integer array to put the results in.
 * count [IN] the number of primes to find.
 */
void findPrimes(uint32_t outputArray[], uint32_t count) {
    uint32_t currentCount = 0;
    uint32_t currentNumber = MINIMAL_DIVIDER;

    while (currentCount < count) {
        if (isPrime(currentNumber)) {
            outputArray[currentCount++] = currentNumber;
        }
        currentNumber++;
    }
}

