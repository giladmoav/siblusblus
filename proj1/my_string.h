#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <ostream>
#include <vector>

namespace my_string {

class MyString {
  public:
    MyString();
    explicit MyString(const char* c_str);
    MyString(std::vector<char>& char_vector);
    MyString(MyString& other);
    MyString& operator=(const MyString& other);

    ~MyString() = default;

    MyString& operator+=(const MyString& other);
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;

    size_t length() const;

    friend MyString operator+(MyString lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream& lhs, const MyString& rhs);

  private:
    std::vector<char> m_char_vector;
};
} // namespace my_string

#endif // !__MY_STRING_H__
