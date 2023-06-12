#include <iostream>
#include<string>

using namespace std;

string str;

void Encrypt(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'x')
			str[i] += 2;
		else if (str[i] == 'y')
			str[i] = 'a';
		else if (str[i] == 'z')
			str[i] = 'b';
		// 转为大写
		str[i] -= 32;
	}
}

void Decode(string& str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'C' && str[i] <= 'Z')
			str[i] -= 2;
		else if (str[i] == 'A')
			str[i] = 'Y';
		else if (str[i] == 'B')
			str[i] = 'Z';
		// 转为大写
		str[i] += 32;
	}
}

int main() {
	cout << "请输入明文：";
	cin >> str;
	Encrypt(str);
	cout << "加密后的文字为：" << str;

	// 解密
	cout << endl;
	cout << "输入密文（大写）：";
	cin >> str;
	Decode(str);
	cout << "解密明文（小写）：" << str << endl;


	system ("pause");
	return 0;
}