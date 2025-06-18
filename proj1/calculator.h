#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <exception>

using std::exception;

constexpr char DIVISION_BY_ZERO_STRING[] = "Division by zero is illegal!";
constexpr char ILLEGAL_CALCULATOR_OPERATION_STRING[] = "Illegal calculator operation!";

constexpr char ADD_SYMBOL = '+';
constexpr char SUBSTRACT_SYMBOL = '-';
constexpr char MULTIPLY_SYMBOL = '*';
constexpr char DIVIDE_SYMBOL = '/';

class DivisionByZeroException : public exception {
  public:
    const char* what() const noexcept override;
};

class IllegalCalculatorOperation : public exception {
  public:
    const char* what() const noexcept override;
};

class Calculator {
  public:
    static double add(double val1, double val2);
    static double substract(double val1, double val2);
    static double multiply(double val1, double val2);
    static double divide(double val1, double val2);
    static double calculate(double val1, char op, double val2);
};

#endif // !__CALCULATOR_H__
