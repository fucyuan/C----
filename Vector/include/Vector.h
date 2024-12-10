#ifndef VECTOR_H
#define VECTOR_H

#include "Allocator.h"
#include <iostream>
#include <stdexcept>

template <typename T, typename Allocator = Allocator<T>>
class Vector {
public:
    Vector(int sz = 10, Allocator allocator = Allocator())
        : first(nullptr), last(nullptr), end_of_storage(nullptr), alloc(allocator), head(new iterator_base()) {
        first = alloc.allocate(sz); // 分配内存
        last = first;
        end_of_storage = first + sz;
    }

    ~Vector() {
        clear();
        alloc.deallocate(first, end_of_storage - first);
        delete head;
    }

    Vector(const Vector<T>& rhs) {
        copy_from(rhs);
    }

    Vector<T>& operator=(const Vector<T>& rhs) {
        if (this != &rhs) {
            clear();
            alloc.deallocate(first, end_of_storage - first);
            copy_from(rhs);
        }
        return *this;
    }

    void push_back(const T& val) {
        if (full()) expand();
        alloc.construct(last, val);
        last++;
    }

    void pop_back() {
        if (empty()) return;
        verify_iterator(last - 1, last); // 检查迭代器是否失效
        alloc.destroy(last - 1);
        last--;
    }

    T back() const {
        if (empty()) throw std::out_of_range("empty vector");
        return *(last - 1);
    }

    int size() const {
        return last - first;
    }

    bool empty() const {
        return last == first;
    }

    bool full() const {
        return last == end_of_storage;
    }

    void expand() {
        int new_size = size() * 2;
        T* new_first = alloc.allocate(new_size);
        for (int i = 0; i < size(); i++) {
            alloc.construct(new_first + i, first[i]);
        }
        clear();
        alloc.deallocate(first, end_of_storage - first);
        first = new_first;
        last = first + size();
        end_of_storage = first + new_size;
    }

    T& operator[](int n) const {
        if (n < 0 || n >= size()) throw std::out_of_range("index out of range");
        return first[n];
    }

    class iterator {
    public:
        iterator(Vector<T, Allocator>* vec, T* p = nullptr)
            : current(p), parent(vec) {}

        bool operator!=(const iterator& rhs) const {
            return current != rhs.current;
        }

        T& operator*() const {
            if (!current) throw std::invalid_argument("iterator not valid");
            return *current;
        }

        iterator& operator++() {
            if (!current) throw std::invalid_argument("iterator not valid");
            current++;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        T* get_current() const { return current; }

        void invalidate() { current = nullptr; } // 标记迭代器失效

    private:
        T* current;
        Vector<T, Allocator>* parent;
    };

    iterator begin() {
        return iterator(this, first);
    }

    iterator end() {
        return iterator(this, last);
    }

    void verify_iterator(T* first, T* last) {
        iterator_base* pre = head;
        iterator_base* it = head->next;
        while (it) {
            if (it->cur->get_current() > first && it->cur->get_current() <= last) {
                it->cur->invalidate(); // 调用迭代器的方法使其失效
                pre->next = it->next;  // 移除失效迭代器
                delete it;
                it = pre->next;
            } else {
                pre = it;
                it = it->next;
            }
        }
    }

    iterator insert(iterator pos, const T& val) {
        if (!pos.get_current()) throw std::invalid_argument("iterator not valid");
        if (full()) expand();
        verify_iterator(pos.get_current() - 1, last); // 检查迭代器是否失效
        T* p = last;
        while (p != pos.get_current()) {
            alloc.construct(p, *(p - 1));
            p--;
        }
        alloc.construct(p, val);
        last++;
        return iterator(this, p);
    }
    iterator erase(iterator pos) {
        if (!pos.get_current()) throw std::invalid_argument("iterator not valid");
        verify_iterator(pos.get_current() - 1, last); // 检查迭代器是否失效
        T* p = pos.get_current();
        while (p != last) {
            alloc.destroy(p);
            alloc.construct(p, *(p + 1));
            p++;
        }
        alloc.destroy(p);
        last--;
        return iterator(this, pos.get_current());
    }

private:
    void clear() {
        for (T* p = first; p != last; p++) {
            alloc.destroy(p);
        }
        last = first;
    }

    void copy_from(const Vector<T>& rhs) {
        int size = rhs.end_of_storage - rhs.first;
        first = alloc.allocate(size);
        int len = rhs.last - rhs.first;
        for (int i = 0; i < len; i++) {
            alloc.construct(first + i, rhs.first[i]);
        }
        last = first + len;
        end_of_storage = first + size;
    }

    T* first;             // 指向数组首元素的指针
    T* last;              // 指向数组尾元素的指针
    T* end_of_storage;    // 指向数组尾后位置的指针
    Allocator alloc;      // 分配器

    struct iterator_base {
        iterator_base(iterator* c = nullptr, iterator_base* n = nullptr)
            : cur(c), next(n) {}
        iterator* cur;
        iterator_base* next;
    };

    iterator_base* head;
};

#endif
