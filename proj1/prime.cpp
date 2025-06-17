#include <cmath>
#include "prime.h"

/// returns true if 'number' is prime
bool is_prime(unsigned int number) {
    for (int i = MINIMAL_DIVIDER; i <= std::sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
