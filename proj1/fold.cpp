#include "fold.h"
#include <iostream>

using std::cout;
using std::endl;

/// print headers of product table of size 'board_size'
void print_column_headers(unsigned int board_size) {
    for (unsigned int i = 1; i <= board_size; i++) {
        cout << "\t" << i;
    }
    cout << endl;
}

/// print rows of product table of size 'board_size'
void print_rows(unsigned int board_size) {
    for (int i = 1; i <= board_size; i++) {
        cout << i;
        for (unsigned int j = 1; j <= board_size; j++) {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
}

/// print a product table given 'board_size'
void print_product_table(unsigned int board_size) {
    print_column_headers(board_size);
    print_rows(board_size);
}
