#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 定义一个加密函数，接受一个字符串参数，返回加密后的字符串
string encrypt(string s) {
    // 遍历字符串中的每个字符
    for (int i = 0; i < s.length(); i++) {
        // 将每个字符的ASCII码加上它在字符串中的位置(1开始)和偏移值3
        s[i] = s[i] + i + 1 + 3;
    }
    // 将字符串的第一位和最后一位调换顺序
    swap(s[0], s[s.length() - 1]);
    // 将字符串反转
    reverse(s.begin(), s.end());
    // 返回加密后的字符串
    return s;
}

// 定义一个解密函数，接受一个字符串参数，返回解密后的字符串
string decrypt(string s) {
    // 将字符串反转
    reverse(s.begin(), s.end());
    // 将字符串的第一位和最后一位调换顺序
    swap(s[0], s[s.length() - 1]);
    // 遍历字符串中的每个字符
    for (int i = 0; i < s.length(); i++) {
        // 将每个字符的ASCII码减去它在字符串中的位置(1开始)和偏移值3
        s[i] = s[i] - i - 1 - 3;
    }
    // 返回解密后的字符串
    return s;
}

// 定义一个主函数，实现用户界面和交互逻辑
int main() {
    // 定义一个变量，用于存储用户选择的操作序号
    int choice;
    // 定义一个变量，用于存储用户输入或输出的密码
    string password;
    // 使用一个循环，让用户可以重复选择操作，直到选择退出为止
    while (true) {
        // 输出提示信息，让用户选择操作
        cout << "请选择操作：" << endl;
        cout << "1. 加密" << endl;
        cout << "2. 解密" << endl;
        cout << "5. 退出" << endl;
        cout << "请输入选项序号：" << endl;
        // 输入用户选择的操作序号
        cin >> choice;
        // 根据用户选择的操作序号，执行相应的功能
        switch (choice) {
        case 1: // 如果用户选择加密
            // 输出提示信息，让用户输入密码
            cout << "请输入要加密的密码（每个字符为数字或者大小写字母，长度不超过16）：" << endl;
            // 输入用户输入的密码
            cin >> password;
            // 调用加密函数，对密码进行加密，并将结果赋值给password变量
            password = encrypt(password);
            // 输出提示信息，显示加密后的密码
            cout << "加密后的密码为：" << password << endl;
            break;
        case 2: // 如果用户选择解密
            // 输出提示信息，让用户输入密码
            cout << "请输入要解密的密码（每个字符为数字或者大小写字母，长度不超过16）：" << endl;
            // 输入用户输入的密码
            cin >> password;
            // 调用解密函数，对密码进行解密，并将结果赋值给password变量
            password = decrypt(password);
            // 输出提示信息，显示解密后的密码
            cout << "解密后的密码为：" << password << endl;
            break;
        case 5: // 如果用户选择退出
            // 输出提示信息，表示程序结束
            cout << "感谢您的使用，再见！" << endl;
            // 退出循环
            return 0;
        default: // 如果用户选择其他无效的序号
            // 输出提示信息，表示输入错误
            cout << "输入错误，请重新输入！" << endl;
        }
    }
    return 0;
}
