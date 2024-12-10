// #include<iostream>
// using namespace std;
/*
1. malloc和new的区别：
malloc和new都是用来动态分配内存的，但是它们的用法和功能有些不同。
malloc和new的区别主要在于：
    1.malloc函数返回的是void*类型的指针，而new运算符返回的是指向具体对象的指针。
    2.malloc函数需要手动释放内存，而new运算符自动释放内存。
    3.malloc函数需要手动计算内存的大小，而new运算符可以自动计算。
    4.malloc函数返回的内存需要手动初始化，而new运算符可以自动初始化。
    5.malloc函数返回的内存需要手动回收，而new运算符自动回收。
    6.malloc函数的调用和释放容易产生内存泄漏，而new运算符的调用和释放不会产生内存泄漏。
    7.malloc只负责开辟内存，而new负责开辟内存和构造对象。
    8.malloc开辟失败时返回NULL，而new运算符抛出bad_alloc异常。
-----------------------------------------------------------------------
2. free和delete的区别：
free和delete都是用来释放动态分配的内存的，但是它们的用法和功能也有些不同。
free和delete的区别主要在于：
    1.delete先调用析构函数，再释放内存，而free只释放内存。

------------------------------------------------------------------------
3.new和delete[]可以混用吗？
    不可以，new和delete[]只能配对使用，不能混用。
    对于普通的编译器内置的类型，new和delete[]可以混用，
    但是对于自定义的类，必须使用delete[]来释放数组。

*/ 



#include"NewAndDelete.h"
int main()
{
    int *p = new int(10);
    std::cout << "The value of *p is " << *p << std::endl;
    delete p;
    int *p2 = new int[5];
    std::cout << "The size of p2 is " << sizeof(p2) << std::endl;
    delete[] p2;



    return 0;
}