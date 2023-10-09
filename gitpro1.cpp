#include <iostream>
#include <string>
using namespace std;

// 加密函数
string encrypt(string s, int offset) {
    // 将每个字符的ASCII码加上它在字符串中的位置(1开始)和偏移值
    for (int i = 0; i < s.length(); i++) {
        s[i] = s[i] + i + 1 + offset;
    }
    // 将字符串的第一位和最后一位调换顺序
    swap(s[0], s[s.length() - 1]);
    // 将字符串反转
    reverse(s.begin(), s.end());
    return s;
}

// 解密函数
string decrypt(string s, int offset) {
    // 将字符串反转
    reverse(s.begin(), s.end());
    // 将字符串的第一位和最后一位调换顺序
    swap(s[0], s[s.length() - 1]);
    // 将每个字符的ASCII码减去它在字符串中的位置(1开始)和偏移值
    for (int i = 0; i < s.length(); i++) {
        s[i] = s[i] - i - 1 - offset;
    }
    return s;
}

int main() {
    // 测试代码
    string input;
    cout << "请输入一个字符串: ";
    cin >> input;
    string output = encrypt(input, 3); // 偏移值为3
    cout << "加密后的字符串为: " << output << endl;
    cout << "解密后的字符串为: " << decrypt(output, 3) << endl;
}
