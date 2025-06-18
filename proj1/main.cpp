#include "complex_math.h"
#include <iostream>

using std::cout;
using std::endl;
using complex::ComplexNumber;

int main() {
    ComplexNumber foo(1, 2);
    ComplexNumber bar(2, 1);
    ComplexNumber baz;
    ComplexNumber baz2(0, 0);

    ComplexNumber add = foo + bar;
    ComplexNumber sub = foo - bar;
    ComplexNumber mul = foo * bar;

    add.print();
    sub.print();
    mul.print();

    cout << "Are these the same:" << endl;
    baz.print();
    baz2.print();
    cout << "Are these the same? " << (baz == baz2) << endl;
}
