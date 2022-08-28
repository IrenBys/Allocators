#include <iostream>
#include "PoolAllocator.h"
#include <assert.h>
#include <algorithm>


using namespace std;


PoolAllocator::PoolAllocator(size_t count_bytes, size_t object_size):
    m_arrSize(count_bytes / object_size),
    m_allBytes(count_bytes),
    m_chunkBytes (object_size) {}

PoolAllocator::~PoolAllocator() {
    free(m_start_ptr);
    m_start_ptr = nullptr;
    m_end_ptr = nullptr;
}

void PoolAllocator::init(){
    assert(m_chunkBytes <= m_allBytes && "Allocator size must be greater than chunk size");
    assert(m_allBytes % m_chunkBytes == 0 && "Allocator size must be a multiple of chunk Size");

    if (m_start_ptr != nullptr) {
        free(m_start_ptr);
    }

    m_start_ptr = malloc(m_allBytes);
    m_end_ptr = m_start_ptr + m_allBytes;

    for(int i = 0; i < m_arrSize; i++)
    {
        m_usedChunkArr[i] = m_start_ptr + m_chunkBytes * i;
    }

    cout << "Pool Allocator size: " << m_allBytes << " bytes" << endl;
    cout << "Pool Allocator chunk size: " << m_chunkBytes << " bytes" << endl;

    cout << "Before allocation" << endl;

    for(int i = 0; i < m_arrSize; i++)
    {
       cout << "Chunk address: " << m_usedChunkArr[i] << endl;
    }
}

void* PoolAllocator::allocate(){
    assert(m_arrSize != 0 && "The pool allocator is full");

    void* currentUsedPtr = m_start_ptr + m_chunkBytes * m_arrSize;
    void* nextUsedPtr = currentUsedPtr - m_chunkBytes;
    m_usedChunkArr[m_arrSize - 1] = nextUsedPtr;
    m_arrSize--;

    cout << "After allocation" << endl;

    for(int i = 0; i < m_arrSize; i++)
    {
        cout << "Chunk address: " << m_usedChunkArr[i] << endl;
    }

    return (void*) nextUsedPtr;
}

void PoolAllocator::deallocate(void* pointer){

    int arr_count = 0;

    for(int i = 0; i < m_arrSize; i++)
    {
        if(pointer != m_usedChunkArr[i])
        {
            cout << "Address out of Allocator memory!"  << endl;
            break;
        }

        arr_count = 1;
    }

    m_arrSize += arr_count;

    cout << "After deallocation" << endl;

    for(int i = 0; i < m_arrSize; i++)
    {
        cout << "Chunk address: " << m_usedChunkArr[i] << endl;
    }
}


