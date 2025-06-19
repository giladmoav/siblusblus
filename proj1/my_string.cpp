#include "my_string.h"

using my_string::MyString;
using std::ostream;
using std::vector;

/// construct an empty string
MyString::MyString() {
    // intentionally empty.
}

/// construct a string based on a C string
MyString::MyString(const char* c_str) {
    size_t string_length = strlen(c_str);
    for (size_t i = 0; i < string_length; i++) {
        m_char_vector.push_back(c_str[i]);
    }
}

/// construct a string based on a char vector
MyString::MyString(vector<char>& char_vector) : m_char_vector(char_vector) {
    // intentially empty.
}

/// copy constructor
MyString::MyString(MyString& other) {
    m_char_vector = other.m_char_vector;
}

/// copy assignment
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }
    m_char_vector = other.m_char_vector;
    return *this;
}

/// compound assignment
MyString& MyString::operator+=(const MyString& other) {
    for (char ch : other.m_char_vector) {
        m_char_vector.push_back(ch);
    }
    return *this;
}

/// equality operator
bool MyString::operator==(const MyString& other) const {
    if (length() != other.length()) {
        return false;
    }
    for (size_t i = 0; i < length(); i++) {
        if (m_char_vector.at(i) != other.m_char_vector.at(i)) {
            return false;
        }
    }
    return true;
}

/// inequality operator
bool my_string::MyString::operator!=(const MyString& other) const {
    return !operator==(other);
}

/// returns the length of the string
size_t MyString::length() const {
    return m_char_vector.size();
}

/// string addition - concat
MyString my_string::operator+(MyString lhs, const MyString& rhs) {
    lhs += rhs;
    return lhs;
}

/// stream insertion - nice for printing
ostream& my_string::operator<<(ostream& lhs, const MyString& rhs) {
    for (char ch : rhs.m_char_vector) {
        lhs << ch;
    }
    return lhs;
}
