#ifndef __COMPLEX_MATH_H__
#define __COMPLEX_MATH_H__

namespace complex {

class ComplexNumber {
  public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    ~ComplexNumber() = default;

    // real part methods
    double get_real_part() const;
    void set_real_part(double real);

    // imaginary part methods
    double get_imaginary_part() const;
    void set_imaginary_part(double imaginary);

    bool operator==(const ComplexNumber& rhs) const;
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    ComplexNumber operator-(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const ComplexNumber& rhs) const;

    void print() const;

  private:
    double m_real;
    double m_imaginary;
};

} // namespace complex

#endif // !__COMPLEX_MATH_H__
