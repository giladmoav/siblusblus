#include "givguv.h"
#include <stdexcept>

using std::hash;
using std::string;

givguv::GivuvMap::GivuvMap(size_t size) : m_size(size), m_count(INITIAL_COUNT) {
    m_values_array = new int[size];
    m_values_bitmap = new bool[size];
}

givguv::GivuvMap::GivuvMap(const GivuvMap& other) {
    m_size = other.m_size;
    m_count = other.m_count;
    std::copy_n(other.m_values_array, m_size, m_values_array);
    std::copy_n(other.m_values_bitmap, m_size, m_values_bitmap);
}

givguv::GivuvMap& givguv::GivuvMap::operator=(const GivuvMap& other) {
    if (this == &other) {
        return *this;
    }
    m_size = other.m_size;
    m_count = other.m_count;
    std::copy_n(other.m_values_array, m_size, m_values_array);
    std::copy_n(other.m_values_bitmap, m_size, m_values_bitmap);
    return *this;
}

givguv::GivuvMap::~GivuvMap() {
    delete[] m_values_array;
    delete[] m_values_bitmap;
}

void givguv::GivuvMap::insert(string& key, int value) {
    size_t index = get_index(key);
    m_values_array[index] = value;
    m_values_bitmap[index] = true;
    m_count++;
}

int givguv::GivuvMap::get(std::string& key) {
    size_t index = get_index(key);
    if (!m_values_bitmap[index]) {
        throw givguv::KeyError();
    }
    return m_values_array[get_index(key)];
}

/// finds a key by searching the value. returns the first result.
void givguv::GivuvMap::find_key(int value) {
    for (size_t i = 0; i < m_size; i++) {
        if (m_values_bitmap[i] && m_values_array[i] == value) {
            return;
        }
    }
}

bool givguv::GivuvMap::exist(std::string& key) {
    return m_values_bitmap[get_index(key)];
}

void givguv::GivuvMap::remove(std::string& key) {
    size_t index = get_index(key);
    if (!m_values_bitmap[index]) {
        throw givguv::KeyError();
    }
    m_values_bitmap[get_index(key)] = false;
    m_count--;
}

size_t givguv::GivuvMap::count() {
    return m_count;
}

size_t inline givguv::GivuvMap::get_index(string& key) {
    return static_cast<size_t>(hash<string>{}(key) % m_size);
}

givguv::KeyError::KeyError() : runtime_error(KEY_ERROR_MSG) {
    // intentially empty
}
