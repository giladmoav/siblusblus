#include "my_string.h"
#include <iostream>

using my_string::MyString;
using std::cout;
using std::endl;

int main() {
    MyString empty;
    MyString foo("foo barrrrrrrr");
    MyString bar("skibidi");
    MyString baz("toilet");

    cout << foo << endl;
    cout << foo + bar << endl;
    cout << foo << endl;
    bar += foo;
    foo += baz;

    cout << foo << endl;
    cout << bar << endl;
    cout << baz << endl;

    cout << "Are these equivalent? \"" << foo << "\" and \"" << bar << "\". " << (foo == bar) << endl;
}
