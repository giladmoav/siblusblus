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

class GivuvMap {
  public:
    GivuvMap(size_t size);
    GivuvMap(const GivuvMap& other);
    GivuvMap& operator=(const GivuvMap& other);

    ~GivuvMap();

    void insert(std::string& key, int value);
    int get(std::string& key);
    void find_key(int value);
    bool exist(std::string& key);
    void remove(std::string& key);
    size_t count();

  private:
    size_t inline get_index(std::string& key);

    size_t m_size;
    size_t m_count;
    int* m_values_array;
    bool* m_values_bitmap;
};

} // namespace givguv

#endif // !__GIVGUV_H__
