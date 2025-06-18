#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::sqrt;

constexpr int ERROR_RETURN_CODE = -1;
constexpr int SUCCESS_RETURN_CODE = 0;

int main() {
    cout << "Please provide an integer: ";

    unsigned long input;
    cin >> input;

    if (!cin) {
        cout << "Make sure the input is a valid positive integer!" << endl;
        return ERROR_RETURN_CODE;
    }

    cout << "Sqrt is: " << sqrt(input) << endl;
    return SUCCESS_RETURN_CODE;
}
