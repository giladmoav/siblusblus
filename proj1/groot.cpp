#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::sqrt;

constexpr int ERROR_RETURN_VALUE = -1;
constexpr int GOOD_RETURN_VALUE = 0;

int main() {
    cout << "Please provide an integer: ";

    unsigned long input;
    cin >> input;

    if (!cin) {
        cout << "Make sure the input is a valid positive integer!" << endl;
        return ERROR_RETURN_VALUE;
    }

    cout << "Sqrt is: " << sqrt(input) << endl;
    return GOOD_RETURN_VALUE;
}
