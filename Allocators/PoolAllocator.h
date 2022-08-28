#include <iostream>
#include <array>


class PoolAllocator{
private:
    void* m_start_ptr = nullptr;    // start address
    void* m_end_ptr = nullptr;      // end address
    size_t m_chunkBytes;            // chunk of memory for allocation
    size_t m_arrSize;               // number of chunk
    size_t m_allBytes;              // size of Allocator
    void* m_usedChunkArr[];         // used chunk memory array

public:
    PoolAllocator(size_t count_bytes, size_t object_size);
    ~PoolAllocator();
    void init();
    void* allocate();
    void deallocate(void* pointer);
};
