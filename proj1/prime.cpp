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

/** 
 * find 'count' primes and put them in 'outputArray'
 * outputArray [OUT] pointer to an unsigned integer array to put the results in.
 * count [IN] the number of primes to find.
 */
void findPrimes(unsigned int outputArray[], unsigned int count) {
    unsigned int currentCount = 0;
    unsigned int currentNumber = MINIMAL_DIVIDER;

    while (currentCount < count) {
        if (isPrime(currentNumber)) {
            outputArray[currentCount++] = currentNumber;
        }
        currentNumber++;
    }
}

