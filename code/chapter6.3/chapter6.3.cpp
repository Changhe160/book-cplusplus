#include<string>
#include<iostream>
#include "Fraction.h"

using namespace std;


int main() {
	//6.3.1
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		a *= b;				//�������ص� * =
		a.operator *= (b);	//�� a*= b �ȼ�
	}
	//6.3.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		//int operator-(int, int); //���󣬲������¶������������
		cout << a << " " << b << endl;
	}

	//6.3.5
	{
		Fraction f;
		f(3, 5); //���ú������������
	}

}
