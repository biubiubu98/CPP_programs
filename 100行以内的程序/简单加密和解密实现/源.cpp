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
		// תΪ��д
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
		// תΪ��д
		str[i] += 32;
	}
}

int main() {
	cout << "���������ģ�";
	cin >> str;
	Encrypt(str);
	cout << "���ܺ������Ϊ��" << str;

	// ����
	cout << endl;
	cout << "�������ģ���д����";
	cin >> str;
	Decode(str);
	cout << "�������ģ�Сд����" << str << endl;


	system ("pause");
	return 0;
}