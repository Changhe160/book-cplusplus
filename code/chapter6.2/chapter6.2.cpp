#include "Fraction.h"
//#include <complex>
class Circle;

class Point {
	friend class Circle;
private:
	double m_x = 0, m_y = 0;
};

class Circle {
	Point m_center;
	double m_radius = 1.0;
public:
	void moveXTo(double val) {
		m_center.m_x = val;
	}
};

int main() {
	Circle a;
	a.moveXTo(1);

	//6.2.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		Fraction c = Fraction(3, 2); //���Ƴ�ʼ��
		Fraction d = 7;		//���Ƴ�ʼ��
		Fraction d2 = 7;	//�����޷��� int ����ת��Ϊ Fraction ���ͣ������ǽ� Fraction ���Ĭ�Ϲ��캯������Ϊ explicit ֮��
	}
}