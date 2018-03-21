#include "Fraction.h"
#include <complex>
Fraction divide(Fraction dividend, Fraction divisor) {
	Fraction result(dividend.numerator()*divisor.denominator(), dividend.denominator()*divisor.numerator());
	return result;
}
Fraction operator/(const Fraction &dividend, const Fraction &divisor) {
	Fraction result(dividend.numerator()*divisor.denominator(), dividend.denominator()*divisor.numerator());
	return result;
}
Fraction operator/(int left, const Fraction &right) {
	return Fraction(left*right.m_denominator, right.m_numerator);
}

bool operator>(const Fraction &lhs, const Fraction &rhs) {
	return lhs.m_numerator*rhs.m_denominator > lhs.m_denominator*rhs.m_numerator;
}


template<typename T, int i>
class fun {
public:
	void foo();
};
template<typename T, int i>
void fun<T, i>::foo() {

}

template <typename T>
const T& getMax(const T &a, const T &b) {
	return a > b ? a : b;
}

int main() {
	//test 6.1.2
	{
		Fraction a; //定义一个对象 a，a 的数据成员使用默认值
		cout << a.value() << endl; //通过对象 a 调用成员函数 value

		//test 6.2.1  if add Fraction(int above, int below): m_numerator(above), m_denominator(below) {}
		//error as following;
		//Fraction a;   
	}
	//test 6.2.2
	{
		Fraction a(1, 5); //直接初始化
		Fraction b(a); //直接初始化，b为对象a的拷贝
		Fraction c = Fraction(3, 2); //复制初始化
		Fraction d = 7; //复制初始化
		Fraction d2 = 7; //错误：无法将 int 类型转换为 Fraction 类型（当我们将 Fraction 类的默认构造函数声明为 explicit 之后）
	}
	//test 6.3
	//print(cout, obj);
	//cout<<obj;

	//test 6.3.1
	{
		Fraction a(1, 5); //直接初始化
		Fraction b(a); //直接初始化，b为对象a的拷贝
		a *= b;//调用重载的 * =
		a.operator *= (b); //与 a*= b 等价
	}
	//test 6.3.2
	{
		Fraction a(1, 5); //直接初始化
		Fraction b(a); //直接初始化，b为对象a的拷贝
	//int operator-(int, int); //错误，不能重新定义内置运算符
		cout << a << " " << b << endl;
	}

	//test 6.3.5
	{
		Fraction f;
		f(3, 5); //调用函数调用运算符
	}

	//test 6.4
	{
		Fraction f = 2; //调用默认构造函数，将 int 类型隐式转换成 Fraction 类型
		double x = 1.5 + f; //调用类型转换运算符，将 f 隐式转换成 double 类型
		int i = f; //正确：首先将 f 隐式转换成 double 类型，然后再转换为 int 类型
	}
	return 0;
}