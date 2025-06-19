#include "miktze.h"
#include <iostream>
#include <new>

using miktze::allocation_header_t;
using std::bad_alloc;
using std::cout;
using std::dec;
using std::endl;
using std::hex;
using std::malloc;
using std::size_t;

// root of the allocations linked list
static allocation_header_t* root_allocation;

/// add 'ptr' to the allocations linked list. does not allocate 'ptr'.
static void list_add(allocation_header_t* header, size_t allocation_size) {
    header->next = nullptr;
    header->allocation_size = allocation_size;

    if (!root_allocation) {
        root_allocation = header;
        return;
    }

    allocation_header_t* current_header = root_allocation;
    while (current_header->next != nullptr) {
        current_header = current_header->next;
    }

    current_header->next = header;
}

/// remove 'ptr' from the allocations linked list. does not free 'ptr'.
/// returns true if removal was successful (i.e. 'ptr' was in the allocations list).
static void list_remove(allocation_header_t* header) {
    // no allocations
    if (root_allocation == nullptr) {
        return;
    }

    // header is root allocation
    if (root_allocation == header) {
        root_allocation = root_allocation->next;
        return;
    }

    // iterate over headers to find 'header'
    allocation_header_t* current_header = root_allocation;
    while (current_header->next != nullptr && current_header->next != header) {
        current_header = current_header->next;
    }

    // header not found
    if (current_header->next == nullptr) {
        return;
    }

    // unlink
    current_header->next = header->next;
}

/// new operator. adds metadata on allocation to linked list.
void* operator new(size_t size) {
    size_t size_with_headers = sizeof(allocation_header_t) + size;

    void* ptr = malloc(size_with_headers);
    if (!ptr) {
        throw bad_alloc{};
    }

    // abuse the data on allocation_header_t's size in compilation to easily get to the "data" offset
    auto header = static_cast<allocation_header_t*>(ptr);
    auto data = static_cast<void*>(header + 1);

    list_add(header, size);
    return data;
}

/// delete operator. removes metadata on allocation to linked list.
void operator delete(void* ptr) {
    // abuse the data on allocation_header_t's size in compilation to easily get to the "header" offset
    auto fake_header = static_cast<allocation_header_t*>(ptr);
    allocation_header_t* header = fake_header - 1;

    list_remove(header);
    free(header);
}

/// delete operator (with size argument). removes metadata on allocation to linked list.
void operator delete(void* ptr, size_t size) {
    // abuse the data on allocation_header_t's size in compilation to easily get to the "header" offset
    operator delete(ptr);
}

/// print information on allocations currently in memory.
void miktze::print_allocations() {
    cout << "Allocations: " << endl;

    allocation_header_t* current_header = root_allocation;
    if (current_header == nullptr) {
        cout << "\tNo allocations" << endl;
    } else {
        while (current_header != nullptr) {
            cout << "\tMemory address: 0x" << hex << (current_header + 1) << ". Size: " << dec
                 << current_header->allocation_size << "." << endl;
            current_header = current_header->next;
        }
    }
}
