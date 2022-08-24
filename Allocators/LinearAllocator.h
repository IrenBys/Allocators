#include <iostream>


using namespace std;


class LinearAllocator{
private:
    void* m_start_ptr = nullptr;    // start address
    size_t m_allBytes;              // size of Allocator
    size_t m_usedBytes;             // used bytes in the Allocator

public:
    LinearAllocator(size_t count_bytes);
    ~LinearAllocator();
    void* allocate(size_t count_bytes);
    void deallocate_all();
};
