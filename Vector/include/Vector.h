#ifndef VECTOR_H
#define VECTOR_H
#include"Allocator.h"
#include <iostream>
template<typename T,typename Allocator = Allocator<T>>
/*容器底层内存开辟和释放由Allocator类负责*/
class Vector {
    public:
        Vector(int sz = 10, Allocator allocator = Allocator()):
            first(nullptr),
            last(nullptr),
            end_of_storage(nullptr),
            alloc(allocator)
           
        {
            // first = new T[sz];
            first = alloc.allocate(sz);//分配内存
            last = first;
            end_of_storage = first + sz;
        }
        ~Vector(){
            // delete[] first;
            for(T* p = first;p!=last;p++){
                alloc.destroy(p);//把指针指向的对象调用析构函数
            }
            alloc.deallocate(first,end_of_storage-first);//释放内存
            first = nullptr;
            last = nullptr;
            end_of_storage = nullptr;
        }
        Vector(const Vector<T>& rhs){
            int size = rhs.end_of_storage - rhs.first;
            // first = new T[size];
            first = alloc.allocate(size);
            int len=rhs.last-rhs.first;
            for(int i=0;i<len;i++){
                // first[i]=rhs.first[i];
                alloc.construct(first+i,rhs.first[i]);
            }
            last = first + len;
            end_of_storage = first + size;
        }
        Vector<T>& operator=(const Vector<T>& rhs){
            if(this!=&rhs){
                // delete[] first;//释放原有内存
                for(T* p = first;p!=last;p++){
                    alloc.destroy(p);//把指针指向的对象调用析构函数
                }
                alloc.deallocate(first,end_of_storage-first);//释放内存
                // int size = rhs.end_of_storage - rhs.first;
                // first = new T[size];
                // int len=rhs.last-rhs.first;
                // for(int i=0;i<len;i++){
                //     first[i]=rhs.first[i];
                // }
                int size = rhs.end_of_storage - rhs.first;
                first = alloc.allocate(size);
                int len=rhs.last-rhs.first;
                for(int i=0;i<len;i++){
                    // first[i]=rhs.first[i];
                    alloc.construct(first+i,rhs.first[i]);
                }
                last = first + len;
                end_of_storage = first + size;
            }
            return *this;
        }
        void push_back(const T& val)//尾插法
        {
           if(full())
           expand();
        //    *last = val;
        //    last++;
            alloc.construct(last,val);
            last++;
        }
        void pop_back(){
            if(empty())
            return;
               
            // last--;
            alloc.destroy(last-1);
            last--;
        }
        T back() const{
            if(empty())
            throw std::out_of_range("empty vector");
            return *(last-1);
        }
        int size() const{
            return last - first;
        }
        bool empty() const{
            return last == first;
        }
        bool full() const{
            return last == end_of_storage;
        }
        void expand(){
            int new_size = size() * 2;
            // T* new_first = new T[new_size];
            T* new_first = alloc.allocate(new_size);
            for(int i=0;i<size();i++){
                // new_first[i] = first[i];
                alloc.construct(new_first+i,first[i]);
            }
            // delete[] first;
            for(T* p = first;p!=last;p++){
                alloc.destroy(p);//把指针指向的对象调用析构函数
            }
            alloc.deallocate(first,end_of_storage-first);//释放内存
            first = new_first;
            last = first + size();
            end_of_storage = first + new_size;
        }
        T& operator[](int n) const{
            if(n < 0 || n >= size())
                throw std::out_of_range("index out of range");
            return first[n];
        }
        class iterator{
            public:
                iterator(T* p):current(p){
                }
                bool operator!=(const iterator& rhs) const{
                    return current != rhs.current;
                }
                T& operator*() const{
                    return *current;
                }
                iterator& operator++(){
                    current++;
                    return *this;
                }
                iterator operator++(int){
                    iterator tmp(*this);
                    current++;
                    return tmp;
                }
            private:
                T* current;
        };
        iterator begin() const{
            return iterator(first);
        }
        iterator end() const{
            return iterator(last);
        }
        
        
private:
   T* first;//指向数组首元素的指针
   T* last;//指向数组尾元素的指针
   T* end_of_storage;//指向数组尾后位置的指针
   Allocator  alloc;//分配器
};
#endif
