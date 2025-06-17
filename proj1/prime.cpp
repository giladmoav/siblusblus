
#include <cmath>


/// returns true if 'number' is prime
bool is_prime(int number) {
    for (int i = 2; i <= std::sqrt(number); i++) {
        if (!(number % i)) {
            return false;
        }
    }
    return true;
}