#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <stdexcept>

using std::runtime_error;

namespace calculator {

constexpr char DIVISION_BY_ZERO_STRING[] = "Division by zero is illegal!";
constexpr char ILLEGAL_CALCULATOR_OPERATION_STRING[] = "Illegal calculator operation!";

constexpr char ADD_SYMBOL = '+';
constexpr char SUBSTRACT_SYMBOL = '-';
constexpr char MULTIPLY_SYMBOL = '*';
constexpr char DIVIDE_SYMBOL = '/';

class DivisionByZeroException : public runtime_error {
  public:
    DivisionByZeroException();
};

class IllegalCalculatorOperation : public runtime_error {
  public:
    IllegalCalculatorOperation();
};

class Calculator {
  public:
    static double add(double val1, double val2);
    static double substract(double val1, double val2);
    static double multiply(double val1, double val2);
    static double divide(double val1, double val2);
    static double calculate(double val1, char op, double val2);
};

} // namespace calculator

#endif // !__CALCULATOR_H__
