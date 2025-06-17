
#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string input;
    std::regex number_regex("\\d+");
    
    std::cout << "Please provide an integer: ";
    std::cin >> input;

    if (!std::regex_match(input, number_regex))
    {
        std::cout << "Make sure the input is a valid positive integer!" << std::endl;
        return -1;
    }

    std::cout << "Sqrt is: " << std::sqrt(std::stoi(input))<< std::endl;
}