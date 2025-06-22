#include "givguv.h"
#include <cstring>
#include <stdexcept>

using givguv::GivuvMap;
using givguv::GivuvNode;
using givguv::KeyError;
using std::copy_n;
using std::hash;
using std::string;

/// regular constructor
GivuvMap::GivuvMap(size_t size) : m_size(size), m_count(INITIAL_COUNT) {
    m_values_array = new GivuvNode[size];
    m_values_bitmap = new bool[size];

    for (size_t i = 0; i < size; i++) {
        m_values_bitmap[i] = false;
    }
}

/// copy constructor
GivuvMap::GivuvMap(const GivuvMap& other) {
    m_size = other.m_size;
    m_count = other.m_count;
    m_values_array = new GivuvNode[m_size];
    m_values_bitmap = new bool[m_size];
    copy_n(other.m_values_array, m_size, m_values_array);
    copy_n(other.m_values_bitmap, m_size, m_values_bitmap);
}

/// copy assignment
GivuvMap& GivuvMap::operator=(const GivuvMap& other) {
    if (this == &other) {
        return *this;
    }
    m_size = other.m_size;
    m_count = other.m_count;
    delete[] m_values_array;
    delete[] m_values_bitmap;
    m_values_array = new GivuvNode[m_size];
    m_values_bitmap = new bool[m_size];
    copy_n(other.m_values_array, m_size, m_values_array);
    copy_n(other.m_values_bitmap, m_size, m_values_bitmap);
    return *this;
}

/// destructor
GivuvMap::~GivuvMap() {
    delete[] m_values_array;
    delete[] m_values_bitmap;
}

/// is subset-equal of other
bool GivuvMap::issubseteq(const GivuvMap& other) const {
    for (size_t i = 0; i < m_size; i++) {
        if (m_values_bitmap[i]) {
            GivuvNode curr_node = m_values_array[i];
            if (!other.exist(curr_node.key) || other.get(curr_node.key) != curr_node.value) {
                return false;
            }
        }
    }
    return true;
}

/// equality operator
bool GivuvMap::operator==(const GivuvMap& other) const {
    return (issubseteq(other) && other.issubseteq(*this));
}

/// inequality operator
bool GivuvMap::operator!=(const GivuvMap& other) const {
    return !operator==(other);
}

/// compound assignment
GivuvMap& GivuvMap::operator+=(const GivuvMap& other) {
    for (size_t i = 0; i < other.m_size; i++) {
        if (other.m_values_bitmap[i]) {
            GivuvNode curr_node = other.m_values_array[i];
            insert(curr_node.key, curr_node.value);
        }
    }
    return *this;
}

/// insert a key-value pair to the map
void GivuvMap::insert(string& key, int value) {
    size_t index = get_index(key);
    m_values_array[index].key = key;
    m_values_array[index].value = value;
    m_values_bitmap[index] = true;
    m_count++;
}

/// get a value from the map based on a key
int GivuvMap::get(string& key) const {
    size_t index = get_index(key);
    if (!m_values_bitmap[index]) {
        throw KeyError();
    }
    return m_values_array[get_index(key)].value;
}

/// finds a key by searching the value. returns the first result.
string GivuvMap::find_key(int value) const {
    for (size_t i = 0; i < m_size; i++) {
        if (m_values_bitmap[i] && m_values_array[i].value == value) {
            return m_values_array[i].key;
        }
    }
    throw KeyError();
}

/// check if a key exists
bool GivuvMap::exist(string& key) const {
    return m_values_bitmap[get_index(key)];
}

/// remove a value from the map based on a key
void GivuvMap::remove(string& key) {
    size_t index = get_index(key);
    if (!m_values_bitmap[index]) {
        throw KeyError();
    }
    m_values_bitmap[get_index(key)] = false;
    m_count--;
}

/// return the count of the key-value pairs in the map
size_t GivuvMap::count() const {
    return m_count;
}

/// return the (hash-modulus) index based on a key
size_t inline GivuvMap::get_index(string& key) const {
    return static_cast<size_t>(hash<string>{}(key) % m_size);
}

/// KeyError constructor
KeyError::KeyError() : runtime_error(KEY_ERROR_MSG) {
    // intentially empty
}

// hash map addition
GivuvMap givguv::operator+(GivuvMap lhs, const GivuvMap& rhs) {
    lhs += rhs;
    return lhs;
}
