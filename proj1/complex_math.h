#ifndef __COMPLEX_MATH_H__
#define __COMPLEX_MATH_H__

namespace complex {
class ComplexNumber {
    double real;
    double imaginary;

  public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);

    // real part methods
    double get_real_part() const;
    void set_real_part(double real);

    // imaginary part methods
    double get_imaginary_part() const;
    void set_imaginary_part(double imaginary);

    bool operator==(const ComplexNumber& rhs);
    ComplexNumber operator+(const ComplexNumber& rhs);
    ComplexNumber operator-(const ComplexNumber& rhs);
    ComplexNumber operator*(const ComplexNumber& rhs);

    void print();
};
} // namespace complex

#endif // !__COMPLEX_MATH_H__
