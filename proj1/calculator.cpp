#include "calculator.h"

/// return val1 + val2
double Calculator::add(double val1, double val2) {
    return val1 + val2;
}

/// return val1 - val2
double Calculator::substract(double val1, double val2) {
    return val1 - val2;
}

/// return val1 * val2
double Calculator::multiply(double val1, double val2) {
    return val1 * val2;
}

/// return val1 / val2
double Calculator::divide(double val1, double val2) {
    if (val2 == 0) {
        throw DivisionByZeroException();
    }
    return val1 / val2;
}

/// return val1 [op] val2
double Calculator::calculate(double val1, char op, double val2) {
    switch (op) {
    case ADD_SYMBOL:
        return add(val1, val2);
    case SUBSTRACT_SYMBOL:
        return substract(val1, val2);
    case MULTIPLY_SYMBOL:
        return multiply(val1, val2);
    case DIVIDE_SYMBOL:
        return divide(val1, val2);
    default:
        throw IllegalCalculatorOperation();
    }
}

/// return a string describing the exception
const char* DivisionByZeroException::what() const noexcept {
    return DIVISION_BY_ZERO_STRING;
}

/// return a string describing the exception
const char* IllegalCalculatorOperation::what() const noexcept {
    return ILLEGAL_CALCULATOR_OPERATION_STRING;
}
