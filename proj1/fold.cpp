
#include <iostream>

constexpr unsigned int BOARD_SIZE = 11;

using std::cout;
using std::endl;

/// print headers of product table of size 'board_size'
void print_column_headers(unsigned int board_size) {
    for (int i = 1; i <= board_size; i++) {
        cout << "\t" << i;
    }
    cout << endl;
}

/// print rows of product table of size 'board_size'
void print_rows(unsigned int board_size) {
    for (int i = 1; i <= board_size; i++) {
        cout << i;
        for (int j = 1; j <= board_size; j++) {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
}

void main() {
    print_column_headers(BOARD_SIZE);
    print_rows(BOARD_SIZE);
}
