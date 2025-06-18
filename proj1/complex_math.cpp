#include "complex_math.h"
#include <iostream>

using std::cout;
using std::endl;
using complex::ComplexNumber;

ComplexNumber::ComplexNumber() : real(0), imaginary(0) {
}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {
}

double ComplexNumber::get_real_part() const {
    return real;
}

void ComplexNumber::set_real_part(double real) {
    this->real = real;
}

double ComplexNumber::get_imaginary_part() const {
    return imaginary;
}

void ComplexNumber::set_imaginary_part(double imaginary) {
    this->imaginary = imaginary;
}

bool ComplexNumber::operator==(const ComplexNumber& rhs) {
    return real == rhs.get_real_part() && imaginary == rhs.get_imaginary_part();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) {
    return ComplexNumber(real + rhs.get_real_part(), imaginary + rhs.get_imaginary_part());
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs) {
    return ComplexNumber(real - rhs.get_real_part(), imaginary - rhs.get_imaginary_part());
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhs) {
    return ComplexNumber(real * rhs.get_real_part() - imaginary * rhs.get_imaginary_part(),
                         real * rhs.get_imaginary_part() + imaginary * rhs.get_real_part());
}

void ComplexNumber::print() {
    cout << real << " + i * " << imaginary << endl;
}
