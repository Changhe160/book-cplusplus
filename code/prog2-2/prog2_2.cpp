#include<iostream>
using namespace std;
int sum = 10;

int main() {
	cout << sum;     // ����ȫ�ֶ���sum�����10
	int sum = 0; 
	cout << sum << endl;//���ʾֲ�����sum�����0
	cout << ::sum;     // ����ȫ�ֶ���sum�����10
	return 0;
}