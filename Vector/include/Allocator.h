#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template <typename T>
class Allocator {     // 定义Allocator类模板
public:
    T* allocate(size_t n) const  // 定义allocate成员函数，返回一个T类型的指针，参数为size_t类型的变量n，表示要分配的内存大小
    {
        return (T*)malloc(n * sizeof(T));   // 调用malloc函数分配内存，并返回一个T类型的指针    
    }
    void deallocate(T* p, size_t n)   // 定义deallocate成员函数，参数为T类型的指针p和size_t类型的变量n，表示要释放的内存大小
    {
        if (p == nullptr)   // 如果指针p为空，则直接返回
            return;
        
        free(p);   // 调用free函数释放内存
    }
    void deallocate(T* p)   // 定义deallocate成员函数，参数为T类型的指针p，表示要释放的内存
    {
        if (p == nullptr)   // 如果指针p为空，则直接返回
            return;
        
        free(p);   // 调用free函数释放内存
    }
    void construct(T* p, const T& value)   // 定义construct成员函数，
    //参数为T类型的指针p和const T&类型的变量value，表示要构造的对象
    {
        new(p) T(value);   //定位new操作符构造对象
    }
    void destroy(T* p)   // 定义destroy成员函数，参数为T类型的指针p，表示要销毁的对象
    {
        p->~T();   // 调用析构函数销毁对象
    }
};

#endif