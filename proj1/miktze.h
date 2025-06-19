#ifndef __MIKTZE_H__
#define __MIKTZE_H__

namespace miktze {

typedef struct _allocation_header_t {
    size_t allocation_size;
    struct _allocation_header_t* next;
} allocation_header_t;

void print_allocations();

} // namespace miktze

void* operator new(size_t size);
void operator delete(void* ptr);
void operator delete(void* ptr, size_t size);

#endif // !__MIKTZE_H__
