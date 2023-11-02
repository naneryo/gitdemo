#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// ����һ�����ܺ���������һ���ַ������������ؼ��ܺ���ַ���
string encrypt(string s) {
    // �����ַ����е�ÿ���ַ�
    for (int i = 0; i < s.length(); i++) {
        // ��ÿ���ַ���ASCII����������ַ����е�λ��(1��ʼ)��ƫ��ֵ3
        s[i] = s[i] + i + 1 + 3;
    }
    // ���ַ����ĵ�һλ�����һλ����˳��
    swap(s[0], s[s.length() - 1]);
    // ���ַ�����ת
    reverse(s.begin(), s.end());
    // ���ؼ��ܺ���ַ���
    return s;
}

// ����һ�����ܺ���������һ���ַ������������ؽ��ܺ���ַ���
string decrypt(string s) {
    // ���ַ�����ת
    reverse(s.begin(), s.end());
    // ���ַ����ĵ�һλ�����һλ����˳��
    swap(s[0], s[s.length() - 1]);
    // �����ַ����е�ÿ���ַ�
    for (int i = 0; i < s.length(); i++) {
        // ��ÿ���ַ���ASCII���ȥ�����ַ����е�λ��(1��ʼ)��ƫ��ֵ3
        s[i] = s[i] - i - 1 - 3;
    }
    // ���ؽ��ܺ���ַ���
    return s;
}

// ����һ������������һ���ַ������������ظ������ǿ�ȵȼ�
string judgePasswordStrength(string s) {
    int length = s.length();
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;

    // �����ַ����е�ÿ���ַ�
    for (int i = 0; i < s.length(); i++) {
        // ������ַ������֣�����֮ǰû�г��ֹ�����
        if (isdigit(s[i]) && !hasDigit) {
            // ��hasDigit��Ϊtrue����ʾ�Ѿ����ֹ�����
            hasDigit = true;
        }
        // ������ַ���Сд��ĸ������֮ǰû�г��ֹ�Сд��ĸ
        if (islower(s[i]) && !hasLower) {
            // ��hasLower��Ϊtrue����ʾ�Ѿ����ֹ�Сд��ĸ
            hasLower = true;
        }
        // ������ַ��Ǵ�д��ĸ������֮ǰû�г��ֹ���д��ĸ
        if (isupper(s[i]) && !hasUpper) {
            // ��hasUpper��Ϊtrue����ʾ�Ѿ����ֹ���д��ĸ
            hasUpper = true;
        }
    }

    // �������볤�Ⱥ��ַ������ж�����ǿ�ȵȼ�����������Ӧ���ַ���
    if (length < 8 || (length >= 8 && (hasDigit + hasLower + hasUpper) == 1)) {
        return "��ǿ��";
    }
    else if (length >= 8 && (hasDigit + hasLower + hasUpper) == 2) {
        return "��ǿ��";
    }
    else if (length >= 8 && (hasDigit + hasLower + hasUpper) == 3) {
        return "��ǿ��";
    }
    else {
        return "��Ч����";
    }
}

// ��������
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
        cout << "��ӭʹ���������ϵͳ\n";
        cout << "==============================\n";
        cout << "��ѡ�������\n";
        cout << "1. ����\n";
        cout << "2. ����\n";
        cout << "3. �ж�����ǿ��\n";
        cout << "4. ��������\n";
        cout << "5. �˳�\n";
        cout << "������ѡ����ţ�";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "==============================\n";
            cout << "������Ҫ���ܵ����룺" << endl;
            cin >> password;
            password = encrypt(password);
            cout << "���ܺ������Ϊ��" << password << endl;
            break;

        case 2:
            cout << "==============================\n";
            cout << "������Ҫ���ܵ����룺" << endl;
            cin >> password;
            password = decrypt(password);
            cout << "���ܺ������Ϊ��" << password << endl;
            break;

        case 3:
            cout << "==============================\n";
            cout << "������Ҫ�ж�ǿ�ȵ����룺" << endl;
            cin >> password;
            cout << "�����������ǿ��Ϊ��" << judgePasswordStrength(password) << endl;
            break;

        case 4:
            int passwordLength;
            cout << "==============================\n";
            cout << "���������볤�ȣ�" << endl;
            cin >> passwordLength;
            if (passwordLength < 1 || passwordLength > 16) {
                cout << "���볤�Ȳ�����Ҫ�����������룡" << endl;
            }
            else {
                string generatedPassword = generatePassword(passwordLength);
                cout << "���ɵ�����Ϊ��" << generatedPassword << endl;
            }
            break;

        case 5:
            cout << "��л����ʹ�ã��ټ���" << endl;
            return 0;

        default:
            cout << "����������������룡" << endl;
            break;
        }
    }

    return 0;
}
