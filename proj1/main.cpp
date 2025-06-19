#include "miktze.h"

using miktze::print_allocations;

int main() {
    print_allocations();
    int* int_ptr1 = new int;
    int* int_ptr2 = new int;
    int* int_ptr3 = new int;
    print_allocations();
    delete int_ptr1;
    print_allocations();
    delete int_ptr2;
    delete int_ptr3;
    print_allocations();
}
