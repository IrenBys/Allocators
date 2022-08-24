#include <iostream>
#include "PoolAllocator.h"
#include <assert.h>
#include <algorithm>


using namespace std;


PoolAllocator::PoolAllocator(size_t count_bytes, size_t object_size){
    m_arrSize = count_bytes / object_size;
    assert(object_size <= count_bytes && "Allocator size must be greater than chunk size");
    assert(count_bytes % object_size == 0 && "Allocator size must be a multiple of chunk Size");

    m_allBytes = count_bytes;
    m_chunkBytes = object_size;

    if (m_start_ptr != nullptr) {
        free(m_start_ptr);
    }
    m_start_ptr = malloc(m_allBytes);

    if (m_end_ptr != nullptr) {
        free(m_end_ptr);
    }
    m_end_ptr = m_start_ptr + m_allBytes;

    for(int i = 0; i < m_arrSize; i++)
    {
        m_usedChunkArr[i] = m_start_ptr + m_chunkBytes * i;
    }
    cout << "Pool Allocator constructor:" << endl;
    cout << "Pool Allocator size: " << m_allBytes << " bytes" << endl;
    cout << "Pool Allocator chunk size: " << m_chunkBytes << " bytes" << endl;
    cout << "Pool Allocator addresses: " << endl;
    for(int i = 0; i < m_arrSize; i++)
    {
       cout  << m_usedChunkArr[i] << endl;
    }
};

PoolAllocator::~PoolAllocator() {
    free(m_start_ptr);
    m_start_ptr = nullptr;
    m_end_ptr = nullptr;
    cout << "Pool Allocator destructor:" << endl;
    cout << "Start Allocator address: " << m_start_ptr << endl;
    cout << "End Allocator address: " << m_end_ptr << endl;

}

void* PoolAllocator::allocate(){
    assert(m_arrSize != 0 && "The pool allocator is full");

    void* currentUsedPtr = m_start_ptr + m_chunkBytes * m_arrSize;
    void* nextUsedPtr = currentUsedPtr - m_chunkBytes;
    m_usedChunkArr[m_arrSize - 1] = nextUsedPtr;
    m_arrSize--;

    cout << "Current address to used bytes pointer " << currentUsedPtr << endl;
    cout << "Return address to used bytes pointer " << nextUsedPtr << endl;
    cout << "Chunk number: " << m_arrSize << endl;

    for(int i = 0; i < m_arrSize; i++)
    {
        cout << m_usedChunkArr[i] << endl;
    }

    return (void*) nextUsedPtr;

}

void PoolAllocator::deallocate(void* pointer){

    //assert(m_start_ptr > i > m_end_ptr && "Address out of Allocator memory!");
    //assert(std::find(m_usedChunkArr, m_end_ptr, pointer) == m_end_ptr && "Address out of Allocator memory!")

    for(int i = 0; i < m_arrSize; i++)
    {
        if(pointer != m_usedChunkArr[i])
        {
            cout << "Address out of Allocator memory!"  << endl;
        } else
        {
            m_usedChunkArr[i] == 0x000000;
        }
    }
    m_arrSize++;
    for(int i = 0; i < m_arrSize; i++)
    {
        cout << m_usedChunkArr[i] << endl;
    }
    cout << "Chunk number: " << m_arrSize << endl;

}

