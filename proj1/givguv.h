#ifndef __GIVGUV_H__
#define __GIVGUV_H__

#include <stdexcept>
#include <string>

constexpr size_t INITIAL_COUNT = 0;
constexpr const char KEY_ERROR_MSG[] = "Key Error: key not found.";

namespace givguv {

class KeyError : public std::runtime_error {
  public:
    KeyError();
};

struct GivuvNode {
    std::string key;
    int value;
};

class GivuvMap {
  public:
    explicit GivuvMap(size_t size);
    GivuvMap(const GivuvMap& other);
    GivuvMap& operator=(const GivuvMap& other);

    ~GivuvMap();

    bool issubseteq(const GivuvMap& other) const;
    bool operator==(const GivuvMap& other) const;
    bool operator!=(const GivuvMap& other) const;
    GivuvMap& operator+=(const GivuvMap& other);

    void insert(std::string& key, int value);
    int get(std::string& key) const;
    std::string find_key(int value) const;
    bool exist(std::string& key) const;
    void remove(std::string& key);
    size_t count() const;

    friend GivuvMap operator+(GivuvMap lhs, const GivuvMap& rhs);

  private:
    size_t inline get_index(std::string& key) const;

    size_t m_size;
    size_t m_count;
    GivuvNode* m_values_array;
    bool* m_values_bitmap;
};

} // namespace givguv

#endif // !__GIVGUV_H__
