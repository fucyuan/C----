

# BigInt 大数运算作业

## 项目简介

本项目实现了一个 `BigInt` 类，用于进行大数的加法和减法运算。`BigInt` 类通过字符串存储大数，并支持任意大小的数字运算，突破了普通整数类型的限制。项目包括大数的加法、减法运算符重载以及数字的反转和输出功能。



## 功能实现

### 1. **大数加法运算符重载 `operator+`**

该运算符实现了大数加法操作。通过从低位到高位逐位加法，并考虑进位，最终返回加法结果。支持任意大小的数字加法。

### 2. **大数减法运算符重载 `operator-`**

该运算符实现了大数减法操作。通过从低位到高位逐位减法，并考虑借位，最终返回减法结果。支持任意大小的数字减法，且支持符号处理。

### 3. **数字反转功能**

为了方便处理大数加法和减法时的进位和借位，提供了一个 `reverseDigits()` 函数来反转数字字符串。

### 4. **输出重载 `operator<<`**

通过重载 `<<` 运算符，可以方便地输出 `BigInt` 对象的值。该方法将字符串中的数字按顺序打印到控制台。

## 类的成员

### `string digits`

存储大数的数字部分，以字符串的形式存储。数字按从低位到高位的顺序排列。

### 构造函数 `BigInt(const string &str)`

通过构造函数初始化 `BigInt` 对象，参数是一个字符串，表示大数。

### `void reverseDigits()`

该函数用于反转 `digits` 字符串。加法和减法过程中需要从低位到高位逐位操作，因此需要反转数字。

### 运算符重载

#### `operator+`

大数加法运算符重载，按位进行加法并处理进位。

```cpp
BigInt operator+(const BigInt &rhs) const;
```

#### `operator-`

大数减法运算符重载，按位进行减法并处理借位。

```cpp
BigInt operator-(const BigInt &rhs) const;
```

### 输出重载 `operator<<`

重载 `<<` 运算符，支持直接输出 `BigInt` 对象。

```cpp
friend ostream& operator<<(ostream &os, const BigInt &num);
```

## 示例代码

### 加法与减法操作示例

```cpp
#include <iostream>
#include "BigInt.h"

int main() {
    // 创建大数对象
    BigInt num1("111");
    BigInt num2("222");

    // 执行加法操作
    BigInt sum = num1 + num2;
    cout << "Sum: " << sum << endl;  // 输出结果：333

    // 执行减法操作
    BigInt diff = num1 - num2;
    cout << "Difference: " << diff << endl;  // 输出结果：-111

    return 0;
}
```

### 编译与运行

1. 编译程序：

   ```bash
   g++ main.cpp -o bigint
   ```

2. 运行程序：

   ```bash
   ./bigint
   ```

## 作业要求

- **加法与减法运算符重载**：实现两个大数的加法与减法，支持进位和借位处理。
- **符号处理**：需要正确处理符号，并考虑大数的大小关系，决定减法的结果符号。
- **字符串操作**：使用字符串存储大数，处理进位、借位及反转等操作。



