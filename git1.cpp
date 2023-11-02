#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

// 定义一个函数，接受一个字符串参数，返回该密码的强度等级
string judgePasswordStrength(string s) {
    int length = s.length();
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;

    // 遍历字符串中的每个字符
    for (int i = 0; i < s.length(); i++) {
        // 如果该字符是数字，并且之前没有出现过数字
        if (isdigit(s[i]) && !hasDigit) {
            // 将hasDigit设为true，表示已经出现过数字
            hasDigit = true;
        }
        // 如果该字符是小写字母，并且之前没有出现过小写字母
        if (islower(s[i]) && !hasLower) {
            // 将hasLower设为true，表示已经出现过小写字母
            hasLower = true;
        }
        // 如果该字符是大写字母，并且之前没有出现过大写字母
        if (isupper(s[i]) && !hasUpper) {
            // 将hasUpper设为true，表示已经出现过大写字母
            hasUpper = true;
        }
    }

    // 根据密码长度和字符类型判断密码强度等级，并返回相应的字符串
    if (length < 8 || (length >= 8 && (hasDigit + hasLower + hasUpper) == 1)) {
        return "弱强度";
    }
    else if (length >= 8 && (hasDigit + hasLower + hasUpper) == 2) {
        return "中强度";
    }
    else if (length >= 8 && (hasDigit + hasLower + hasUpper) == 3) {
        return "高强度";
    }
    else {
        return "无效密码";
    }
}

// 生成密码
string generatePassword(int length) {
    const string validChars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string generatedPassword;
    for (int i = 0; i < length; i++) {
        generatedPassword += validChars[rand() % validChars.length()];
    }
    return generatedPassword;
}

int main() {
    srand(time(0));
    int choice;
    string password;

    while (true) {
        cout << "==============================\n";
        cout << "欢迎使用密码管理系统\n";
        cout << "==============================\n";
        cout << "请选择操作：\n";
        cout << "1. 加密\n";
        cout << "2. 解密\n";
        cout << "3. 判断密码强度\n";
        cout << "4. 密码生成\n";
        cout << "5. 退出\n";
        cout << "请输入选项序号：";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "==============================\n";
            cout << "请输入要加密的密码：" << endl;
            cin >> password;
            password = encrypt(password);
            cout << "加密后的密码为：" << password << endl;
            break;

        case 2:
            cout << "==============================\n";
            cout << "请输入要解密的密码：" << endl;
            cin >> password;
            password = decrypt(password);
            cout << "解密后的密码为：" << password << endl;
            break;

        case 3:
            cout << "==============================\n";
            cout << "请输入要判断强度的密码：" << endl;
            cin >> password;
            cout << "您输入的密码强度为：" << judgePasswordStrength(password) << endl;
            break;

        case 4:
            int passwordLength;
            cout << "==============================\n";
            cout << "请输入密码长度：" << endl;
            cin >> passwordLength;
            if (passwordLength < 1 || passwordLength > 16) {
                cout << "密码长度不符合要求，请重新输入！" << endl;
            }
            else {
                string generatedPassword = generatePassword(passwordLength);
                cout << "生成的密码为：" << generatedPassword << endl;
            }
            break;

        case 5:
            cout << "感谢您的使用，再见！" << endl;
            return 0;

        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
    }

    return 0;
}
