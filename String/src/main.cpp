#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String str1 = "Hello, world!";
    String str2 = "Hello, C++!";
    String str3 = "Hello, C++11!";
    String str4 = str1 + "    " + str2 + " " + str3;

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    for(String::Iterator it = str4.begin(); it != str4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for(char ch : str3) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}