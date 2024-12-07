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
        int i = 0, j = 0;

        // 从个位开始遍历，进行加法操作
        while (i < digits.size() || j < rhs.digits.size() || carry) {
            // 填空1：获取当前位置数字并进行相加，考虑进位
            int sum = 0;
            // 填空2：计算进位

            // 填空3：记录加法结果

            i++;
            j++;
        }

        reverse(result.begin(), result.end()); // 反转结果
        return BigInt(result);  // 返回结果
    }

    // 大数减法运算符重载
    BigInt operator-(const BigInt &rhs) const {
        string result;
        int borrow = 0;
        int i = 0, j = 0;

        // 填空4：确定哪个数较大，决定结果的符号
        // 填空5：从个位开始遍历，进行减法操作，考虑借位

        while (i < digits.size() || j < rhs.digits.size() || borrow) {
            // 填空6：获取当前位置数字并进行相减，考虑借位
            int diff = 0;

            if (diff < 0) {
                // 填空7：如果结果小于0，借位
            }

            // 填空8：记录减法结果

            i++;
            j++;
        }

        // 填空9：删除结果字符串前的多余零
        while (result.size() > 1 && result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end()); // 反转结果
        return BigInt(result);  // 返回结果
    }
};

int main() {
    BigInt num1("111");
    BigInt num2("222");

    // 加法
    BigInt sum = num1 + num2;
    cout << "Sum: " << sum << endl;

    // 减法
    BigInt diff = num1 - num2;
    cout << "Difference: " << diff << endl;

    return 0;
}
