#include "Fraction.h"

int main() {

	//6.2.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		Fraction c = Fraction(3, 2); //���Ƴ�ʼ��
		Fraction d = 7;		//���Ƴ�ʼ��
		Fraction d2 = 7;	//�����޷��� int ����ת��Ϊ Fraction ���ͣ������ǽ� Fraction ���Ĭ�Ϲ��캯������Ϊ explicit ֮��
	}
}