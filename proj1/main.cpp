<<<<<<< HEAD
#include <iostream>

int main() {
    std::cout << "Hello World!\n";
=======
#include "calculator.h"
#include <iostream>

using std::cout;
using std::endl;

constexpr char ILLEGAL_OPERATION = ' ';

int main() {
    cout << "2.1 + 3.2 = " << Calculator::add(2.1, 3.2) << endl;
    cout << "2.2 - 3.2 = " << Calculator::substract(2.2, 3.1) << endl;
    cout << "2.3 * 3.3 = " << Calculator::multiply(2.3, 3.3) << endl;
    cout << "2.4 / 3.5 = " << Calculator::divide(2.4, 3.5) << endl;

    cout << "Lets check division by zero!" << endl;
    try {
        cout << "Should fail: " << Calculator::divide(2.1, 0) << endl;
    } catch (const DivisionByZeroException& exception) {
        cout << "Good! We got exception: " << exception.what() << endl;
    }

    cout << "Now using Calculator::calculate :" << endl;
    cout << "2.1 + 3.2 = " << Calculator::calculate(2.1, ADD_SYMBOL, 3.2) << endl;
    cout << "2.2 - 3.2 = " << Calculator::calculate(2.2, SUBSTRACT_SYMBOL, 3.1) << endl;
    cout << "2.3 * 3.3 = " << Calculator::calculate(2.3, MULTIPLY_SYMBOL, 3.3) << endl;
    cout << "2.4 / 3.5 = " << Calculator::calculate(2.4, DIVIDE_SYMBOL, 3.5) << endl;

    cout << "Lets check illegal calculator operation!" << endl;
    try {
        cout << "Should fail: " << Calculator::calculate(2.1, ILLEGAL_OPERATION, 3.2) << endl;
    } catch (const IllegalCalculatorOperation& exception) {
        cout << "Good! We got exception: " << exception.what() << endl;
    }
>>>>>>> Add caclulator
}
