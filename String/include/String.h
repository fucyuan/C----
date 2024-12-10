#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>



class String {
    private:
        char* str;
        
    public:
        String(const char* s = nullptr) {
            if (s == nullptr) {
                str = new char[1];
                str[0] = '\0';
            } else {
                 str = new char[strlen(s) + 1];
                 strcpy(str, s);
            }
        }
        ~String() {
            delete[] str;
            str = nullptr;
        }
        String(const String& s) {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        String& operator=(const String& s) {
            if (this == &s) {
                return *this;
            }
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const String& s) {
            os << s.str;
            return os;
        }
        friend std::istream& operator>>(std::istream& is, String& s) {
            char* temp = new char[1000];
            is >> temp;
            delete[] s.str;
            s.str = new char[strlen(temp) + 1];
            strcpy(s.str, temp);
            delete[] temp;
            return is;
        }
        friend String operator+(const String& s1, const String& s2) {
            String temp(s1.str);
            temp += s2.str;
            return temp;
        }
        String& operator+=(const char* s) {
            char* temp = new char[strlen(s) + strlen(str) + 1];
            strcpy(temp, str);//copy the original string
            strcat(temp, s);//add the new string
            delete[] str;
            str = temp;
            return *this;
        }
        int length() const {
            return strlen(str);
        }
        char& operator[](int i) {
            return str[i];
        }
        const char& operator[](int i) const {
            return str[i];
        }
        const char* c_str() const {
            return str;
        }
        class Iterator {
            private:
                const char* ptr;
            public:
                Iterator(const char* p) : ptr(p) {}
                char& operator*() {
                    return const_cast<char&>(*ptr);
                }
                Iterator& operator++() //prefix++返回引用
                {
                    ptr++;
                    return *this;
                }
                Iterator operator++(int) //postfix++返回临时对象
                {
                    Iterator temp = *this;
                    ptr++;
                    return temp;
                }
                bool operator!=(const Iterator& other) const {
                    return ptr != other.ptr;
                }
        };
        Iterator begin() const {
            return Iterator(str);
        }
        Iterator end() const {
            return Iterator(str + strlen(str));
        }        
        
};

#endif
        