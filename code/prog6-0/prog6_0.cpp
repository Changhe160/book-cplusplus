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
		Fraction a; //����һ������ a��a �����ݳ�Աʹ��Ĭ��ֵ
		cout << a.value() << endl; //ͨ������ a ���ó�Ա���� value

		//test 6.2.1  if add Fraction(int above, int below): m_numerator(above), m_denominator(below) {}
		//error as following;
		//Fraction a;   
	}
	//test 6.2.2
	{
		Fraction a(1, 5); //ֱ�ӳ�ʼ��
		Fraction b(a); //ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		Fraction c = Fraction(3, 2); //���Ƴ�ʼ��
		Fraction d = 7; //���Ƴ�ʼ��
		Fraction d2 = 7; //�����޷��� int ����ת��Ϊ Fraction ���ͣ������ǽ� Fraction ���Ĭ�Ϲ��캯������Ϊ explicit ֮��
	}
	//test 6.3
	//print(cout, obj);
	//cout<<obj;

	//test 6.3.1
	{
		Fraction a(1, 5); //ֱ�ӳ�ʼ��
		Fraction b(a); //ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		a *= b;//�������ص� * =
		a.operator *= (b); //�� a*= b �ȼ�
	}
	//test 6.3.2
	{
		Fraction a(1, 5); //ֱ�ӳ�ʼ��
		Fraction b(a); //ֱ�ӳ�ʼ����bΪ����a�Ŀ���
	//int operator-(int, int); //���󣬲������¶������������
		cout << a << " " << b << endl;
	}

	//test 6.3.5
	{
		Fraction f;
		f(3, 5); //���ú������������
	}

	//test 6.4
	{
		Fraction f = 2; //����Ĭ�Ϲ��캯������ int ������ʽת���� Fraction ����
		double x = 1.5 + f; //��������ת����������� f ��ʽת���� double ����
		int i = f; //��ȷ�����Ƚ� f ��ʽת���� double ���ͣ�Ȼ����ת��Ϊ int ����
	}
	return 0;
}