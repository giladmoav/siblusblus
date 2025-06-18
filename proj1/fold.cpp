#include "fold.h"
#include <iostream>

using std::cout;
using std::endl;

/// print headers of product table of size 'board_size'
void printColumnHeaders(unsigned int board_size) {
    for (unsigned int i = 1; i <= board_size; i++) {
        cout << "\t" << i;
    }
    cout << endl;
}

/// print rows of product table of size 'board_size'
void printRows(unsigned int board_size) {
    for (int i = 1; i <= board_size; i++) {
        cout << i;
        for (unsigned int j = 1; j <= board_size; j++) {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
}

/// print a product table given 'board_size'
void printProductTable(unsigned int board_size) {
    printColumnHeaders(board_size);
    printRows(board_size);
}
