/*
*����һ���ı�ͳ�������ַ��ĸ���
*/
#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	char digit;
	do {
		digit = cin.get();
		if (digit >= '0'&&digit <= '9') ++cnt;
	} while (digit != EOF);

	cout << "�����ַ�����Ϊ�� " << cnt << endl;
	return 0;
}