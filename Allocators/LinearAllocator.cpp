#include <iostream>
#include "LinearAllocator.h"
#include <assert.h>


using namespace std;


LinearAllocator::LinearAllocator(size_t count_bytes){
    m_allBytes = count_bytes;
    m_usedBytes = 0;

    if (m_start_ptr != nullptr) {
        free(m_start_ptr);
    }
    m_start_ptr = malloc(m_allBytes);

    cout << "Linear Allocator size: " << m_allBytes << " bytes" << endl;
    cout << "Start Allocator address: " << m_start_ptr << endl;
};

LinearAllocator::~LinearAllocator() {
    free(m_start_ptr);
    m_start_ptr = nullptr;
    cout << "Linear Allocator destructor" << endl;
}

void* LinearAllocator::allocate(size_t count_bytes){
    assert(count_bytes + m_usedBytes <= m_allBytes && "Requested memory for allocation is more than possible");

    void* currentUsedPtr = m_start_ptr;
    m_usedBytes += count_bytes;
    void* nextUsedPtr = currentUsedPtr + m_usedBytes;

    cout << "Already used bytes in the Allocator: " << m_usedBytes << endl;
    cout << "Current address to used bytes pointer " << currentUsedPtr << endl;
    cout << "Return address to used bytes pointer " << nextUsedPtr << endl;

    return (void*) nextUsedPtr;
}

void LinearAllocator::deallocate_all(){
    m_usedBytes = 0;
    cout << "Start address after deallocation: " << m_start_ptr << endl;
    cout << "Used bytes after deallocation " << m_usedBytes << endl;
}


