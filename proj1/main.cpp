#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;

class Ex1 {

  public:
    /// check if num is prime
    bool operator()(uint32_t num) {
        double double_num = static_cast<double>(num);
        auto sqrt_num = static_cast<uint32_t>(sqrt(double_num));
        for (uint32_t i = MINIMAL_DIVIDER; i <= sqrt_num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

  private:
    const uint32_t MINIMAL_DIVIDER = 2;
};

class Ex2 {

  public:
    /// check if first value is bigger than the second
    bool operator()(pair<int, int> number_pair) {
        return number_pair.first > number_pair.second;
    }
};

class Ex3 {

  public:
    explicit Ex3(int n) : m_number(n) {
        // intentially empty
    }

    /// check if another_number is divisible by the number given in the constructor
    bool operator()(int another_number) {
        return !(another_number % m_number);
    }

  private:
    int m_number;
};

/// ex4. 
class ConstantFunctor {

  public:
    explicit ConstantFunctor(int n) : m_number(n) {
        // intentially empty
    }

    /// return the initial value provided in the constructor
    int operator()(int another_number) {
        return m_number;
    }

  private:
    int m_number;
};
int main() {
    // ex1
    cout << "58 is prime? " << Ex1()(58) << endl;
    cout << "57 is prime? " << Ex1()(59) << endl;

    // ex2
    cout << "Is 57 bigger than 58? " << Ex2()(make_pair(57, 58)) << endl;

    // ex3
    cout << "Is 4 a divider of 56? " << Ex3(4)(56) << endl;

    // ex4
    auto foo = ConstantFunctor(1337);
    cout << "What happens if I call it with 45? " << foo(45) << endl;
    cout << "And what about 63? " << foo(63) << endl;
}
