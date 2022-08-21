#include <iostream>
#include "LinearAllocator.h"


using namespace std;


int main()
{
    LinearAllocator linear_allocator(10);
    cout << endl;
    linear_allocator.allocate(4);
    cout << endl;
    linear_allocator.deallocate_all();
    cout << endl;
    linear_allocator.allocate(8);
    cout << endl;
    linear_allocator.deallocate_all();
    return 0;
}
