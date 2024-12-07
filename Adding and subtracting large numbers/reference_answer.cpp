#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigInt {
public:
    string digits;  // 存储大数的字符串

    // 构造函数
    BigInt(const string &str) : digits(str) {}

    // 反转字符串
    void reverseDigits() {
        reverse(digits.begin(), digits.end());
    }

    // 输出重载
    friend ostream& operator<<(ostream &os, const BigInt &num) {
        os << num.digits;
        return os;
    }

    // 大数加法运算符重载
    BigInt operator+(const BigInt &rhs) const {
        string result;
        int carry = 0;
        int i = digits.size()-1, j = rhs.digits.size()-1;

        // 从个位开始遍历，进行加法操作
        while (i < digits.size() || j < rhs.digits.size() || carry) {
            // 填空1：获取当前位置数字并进行相加，考虑进位
            int sum = ((i < digits.size())? (digits[i] - '0') : 0)+
            ((j < rhs.digits.size())? (rhs.digits[j] - '0') : 0)+carry;   
             
            // 填空2：计算进位
            carry = sum / 10;
            // 填空3：记录加法结果
            result.push_back(sum % 10 + '0');  // 注意：这里需要把数字转换为字符再push_back
            i--;
            j--;
        }

        reverse(result.begin(), result.end()); // 反转结果
        return BigInt(result);  // 返回结果
    }
    bool operator<(const BigInt &rhs) const {
        if (digits.size() != rhs.digits.size()) {
            return digits.size() < rhs.digits.size();  // 比较长度
        }
        return digits < rhs.digits;  // 长度相等时比较字符串    

    }
    bool operator==(const BigInt &rhs) const {
        return digits == rhs.digits;
    }
    bool operator>(const BigInt &rhs) const {
        return rhs < *this;
    }
    
    // 重载负号

    // 大数减法运算符重载
   BigInt operator-(const BigInt &rhs) const {
    string result;
    int borrow = 0;
    int i, j;
    BigInt tempBigInt = *this, tempSmallInt = rhs;

    // 确定较大数，决定符号
    if (*this == rhs) {
        return BigInt("0");
    }
    if (rhs > *this) {  // 若被减数小于减数，调整顺序并记录符号
        tempBigInt = rhs;
        tempSmallInt = *this;   
    }

    // 从高位到低位遍历
    i = tempBigInt.digits.size() - 1;
    j = tempSmallInt.digits.size() - 1;

    while (i >= 0 || j >= 0 || borrow) {
        // 获取当前位置数字并进行相减，考虑借位
        int diff = ((i >= 0) ? (tempBigInt.digits[i] - '0') : 0) -
                   ((j >= 0) ? (tempSmallInt.digits[j] - '0') : 0) - borrow;

        // 计算借位
        borrow = (diff < 0) ? 1 : 0;

        // 记录减法结果
        result.push_back((diff + 10) % 10 + '0');
        i--;
        j--;
    }
    if(rhs > *this)
    result.push_back('-');  // 记录符号

    // 删除多余的前导零
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    // 确保负号在结果字符串的正确位置
    if (result.back() == '-') {
        result.pop_back();
        result.push_back('-');
    }

    reverse(result.begin(), result.end());  // 确保结果顺序正确
    return BigInt(result);
}

};

int main() {
    BigInt num1("100");
    BigInt num2("99");

    // 加法
    BigInt sum = num1 + num2;
    cout << "Sum: " << sum << endl;

    // 减法
    BigInt diff = num1 - num2;
    cout << "Difference: " << diff << endl;

    return 0;
}
