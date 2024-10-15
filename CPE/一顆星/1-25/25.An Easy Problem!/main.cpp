#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// 將單個字符轉換為數值
int charToValue(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    else if ('a' <= c && c <= 'z')
        return c - 'a' + 36;
    return -1; // 理論上不會發生，因為輸入保證有效
}

// 將字符串轉換為指定基數下的十進制數值
long long toDecimal(const string& number, int base) {
    long long value = 0;
    for (char c : number) {
        value = value * base + charToValue(c);
        if (value < 0) // 防止溢出
            return -1;
    }
    return value;
}

// 找到最小的基數 N 使得該數字能被 N-1 整除
int findMinBase(const string& number) {
    // 找到數字中最大的字符對應的最小基數
    int minBase = 2;
    for (char c : number) {
        minBase = max(minBase, charToValue(c) + 1);
    }

    // 從最小基數開始檢查是否能被 (base-1) 整除
    for (int base = minBase; base <= 62; base++) {
        long long decimalValue = toDecimal(number, base);
        if (decimalValue < 0) // 如果溢出，跳過這個基數
            continue;
        if (decimalValue % (base - 1) == 0)
            return base;
    }

    return -1; // 找不到合適的基數
}

int main() {
    string number;
    while (cin >> number) {
        int result = findMinBase(number);
        if (result == -1) {
            cout << "such number is impossible!" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}