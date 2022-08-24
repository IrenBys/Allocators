#include <iostream>
#include "LinearAllocator.h"
#include "PoolAllocator.h"

// Macros for Linear Allocator
#define LINEAR_ALLOCATOR_SIZE 10
#define LA_ALLOCATED_MEMORY_ 10

// Macros for Pool Allocator
#define POOL_ALLOCATOR_SIZE 10
#define PA_MEMORY_CHUNK 2


using namespace std;


int main()
{
    void* i;
    cout << "**************************************" <<endl;
    cout << "*          Linear Allocator          *" <<endl;
    cout << "**************************************" <<endl;
    cout << endl;
    LinearAllocator linear_allocator(LINEAR_ALLOCATOR_SIZE);
    cout << endl;
    linear_allocator.allocate(LA_ALLOCATED_MEMORY_);
    cout << endl;
    linear_allocator.deallocate_all();
    cout << endl;
    cout << endl;

    cout << "*************************************" <<endl;
    cout << "*           Pool Allocator          *" <<endl;
    cout << "*************************************" <<endl;
    cout << endl;
    PoolAllocator poll_allocator(POOL_ALLOCATOR_SIZE, PA_MEMORY_CHUNK);
    cout << endl;
    poll_allocator.allocate();
    cout << endl;
    poll_allocator.allocate();
    cout << endl;
    poll_allocator.allocate();
    cout << endl;
    poll_allocator.allocate();
    cout << endl;
    cin >> i;
    poll_allocator.deallocate(i);

    return 0;
}
