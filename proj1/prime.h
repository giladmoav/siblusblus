#ifndef __PRIME_H__
#define __PRIME_H__

#include <cstdint>

constexpr uint32_t MINIMAL_DIVIDER = 2;

bool isPrime(uint32_t number);
void findPrimes(uint32_t output_array[], uint32_t count);

#endif // !__PRIME_H__

