#include"NewAndDelete.h"

void* operator new(size_t size)
{   void *p = malloc(size);
    if(p == NULL)
    {
        throw std::bad_alloc();
        std::cerr << "Memory allocation failed!" << std::endl;
    }
    std::cout << "Memory allocated at " << p << std::endl;
    return p;
}

void operator delete(void *p) noexcept
{
    std::cout << "Memory deallocated at " << p << std::endl;
    free(p);   
}
void* operator new[](size_t size)
{
    if(size == 0)
    {
        
        std::cerr << "Array size is 0!" << std::endl;
        throw std::bad_alloc();
    }
    std::cout << "Array memory allocated at " << size << std::endl;
    return operator new(size);
}

void operator delete[](void *p) noexcept
{
    std::cout << "Array memory deallocated at " << p << std::endl;
    operator delete(p);
}

