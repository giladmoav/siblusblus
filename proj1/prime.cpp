#include "prime.h"
#include <cmath>

/// returns true if 'number' is prime
bool is_prime(unsigned int number) {
    long double long_double_number = static_cast<long double>(number);
    int maximal_divider = static_cast<int>(std::sqrt(long_double_number));
    for (int i = MINIMAL_DIVIDER; i <= maximal_divider; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
