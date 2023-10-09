#include <iostream>
#include <string>
using namespace std;

// ���ܺ���
string encrypt(string s, int offset) {
    // ��ÿ���ַ���ASCII����������ַ����е�λ��(1��ʼ)��ƫ��ֵ
    for (int i = 0; i < s.length(); i++) {
        s[i] = s[i] + i + 1 + offset;
    }
    // ���ַ����ĵ�һλ�����һλ����˳��
    swap(s[0], s[s.length() - 1]);
    // ���ַ�����ת
    reverse(s.begin(), s.end());
    return s;
}

// ���ܺ���
string decrypt(string s, int offset) {
    // ���ַ�����ת
    reverse(s.begin(), s.end());
    // ���ַ����ĵ�һλ�����һλ����˳��
    swap(s[0], s[s.length() - 1]);
    // ��ÿ���ַ���ASCII���ȥ�����ַ����е�λ��(1��ʼ)��ƫ��ֵ
    for (int i = 0; i < s.length(); i++) {
        s[i] = s[i] - i - 1 - offset;
    }
    return s;
}

int main() {
    // ���Դ���
    string input;
    cout << "������һ���ַ���: ";
    cin >> input;
    string output = encrypt(input, 3); // ƫ��ֵΪ3
    cout << "���ܺ���ַ���Ϊ: " << output << endl;
    cout << "���ܺ���ַ���Ϊ: " << decrypt(output, 3) << endl;
}
