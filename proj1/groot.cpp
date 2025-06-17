
#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_match;
using std::sqrt;
using std::stoul;
using std::string;
using std::out_of_range;

constexpr int ERROR_RETURN_VALUE = -1;
const regex NUMBER_REGEX("\\d+");

int main() {
    cout << "Please provide an integer: ";

    string input;
    cin >> input;

    if (!regex_match(input, NUMBER_REGEX)) {
        cout << "Make sure the input is a valid positive integer!" << endl;
        return ERROR_RETURN_VALUE;
    }

    unsigned long input_long;
    try {
        input_long = stoul(input);
    } catch (out_of_range) {
        cout << "Make sure the input is in range!" << endl;
        return ERROR_RETURN_VALUE;
    }

    cout << "Sqrt is: " << sqrt(input_long) << endl;
}