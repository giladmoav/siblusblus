#include "complex_math.h"
#include <iostream>

using complex::ComplexNumber;
using std::cout;
using std::endl;

/// construct a "zero" complex number
ComplexNumber::ComplexNumber() : m_real(0), m_imaginary(0) {
}

/// construct a complex number given the real and imaginary denominators
ComplexNumber::ComplexNumber(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {
}

/// get the real part of a complex number
double ComplexNumber::get_real_part() const {
    return m_real;
}

/// set the real part of a complex number
void ComplexNumber::set_real_part(double real) {
    m_real = real;
}

/// get the imaginary part of a complex number
double ComplexNumber::get_imaginary_part() const {
    return m_imaginary;
}

/// set the imaginary part of a complex number
void ComplexNumber::set_imaginary_part(double imaginary) {
    m_imaginary = imaginary;
}

/// check if two complex numbers are equivalent
bool ComplexNumber::operator==(const ComplexNumber& rhs) const {
    return m_real == rhs.get_real_part() && m_imaginary == rhs.get_imaginary_part();
}

/// add two complex numbers
ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) const {
    return ComplexNumber(m_real + rhs.get_real_part(), m_imaginary + rhs.get_imaginary_part());
}

/// substract two complex numbers
ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs) const {
    return ComplexNumber(m_real - rhs.get_real_part(), m_imaginary - rhs.get_imaginary_part());
}

/// multiply two complex numbers
ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhs) const {
    return ComplexNumber(m_real * rhs.get_real_part() - m_imaginary * rhs.get_imaginary_part(),
                         m_real * rhs.get_imaginary_part() + m_imaginary * rhs.get_real_part());
}

/// print a complex number
void ComplexNumber::print() const {
    cout << m_real << " + i * " << m_imaginary << endl;
}
