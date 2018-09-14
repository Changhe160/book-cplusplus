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
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		Fraction c = Fraction(3, 2); //复制初始化
		Fraction d = 7;		//复制初始化
		Fraction d2 = 7;	//错误：无法将 int 类型转换为 Fraction 类型（当我们将 Fraction 类的默认构造函数声明为 explicit 之后）
	}
}