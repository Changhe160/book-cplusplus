/*
*���ٷ��Ƶ�ѧ���ɼ�ת�����弶�ƣ�����ɼ���90�ֵ�100�ַ�Χ�ڣ�����90�ֺ�100�֣���
*��ת����A��80�ֵ�90�ַ�Χ��Ϊ B������80�ֲ�����90�֣����������ƣ�60������ΪF
*/
#include<iostream>
using namespace std;

int main() {
	int score;
	cout << "������һ������:";
	cin >> score;

	if (score < 60) {
		cout << "F" << endl;
	}
	else if (score < 70) {
		cout << "D" << endl;
	}
	else if (score < 80) {
		cout << "C" << endl;
	}
	else if (score < 90) {
		cout << "B" << endl;
	}
	else {
		cout << "A" << endl;
	}
	
	return 0;
}