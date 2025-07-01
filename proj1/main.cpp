#include "prog.h"
#include <iostream>

using prog::technician;
using std::cout;
using std::endl;
using std::exception;

int main() {
    try {
        technician();
    } catch (exception& err) {
        cout << "Caught exception: " << err.what() << endl;
    }
    return 0;
}
