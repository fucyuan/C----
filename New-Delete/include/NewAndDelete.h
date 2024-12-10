#ifndef NEW_AND_DELETE_H
#define NEW_AND_DELETE_H
#include<iostream>


void* operator new(size_t size);
void operator delete(void* ptr)noexcept;
void* operator new[](size_t size);
void operator delete[](void* ptr)noexcept;

#endif