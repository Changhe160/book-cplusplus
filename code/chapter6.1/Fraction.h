//分数类

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;


//6.1.1
class Fraction {
	int m_numerator = 0;			// 分子
	int m_denominator = 1;			//分母
public:
	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
	double value() const;			//计算分数值
	void reduce();					//约分
	
	friend ostream& print(ostream &os, const Fraction &a){
		//os << a.m_numerator << "/" << a.m_denominator;//错误：不能访问私有成员
		os << a.numerator() << "/" << a.denominator();
		return os;
	}

private:
	int gcd(int x, int y); //计算x和y的最大公约数
};

//6.1.2
inline double Fraction::value() const {
	return static_cast<double>(m_numerator) / m_denominator;
}

//ostream& print(ostream &os, const Fraction &a);

////6.1.5
//ostream& Fraction::print(ostream &os, const Fraction &a) {
//	//os << a.m_numerator << "/" << a.m_denominator;//错误：不能访问私有成员
//	os << a.numerator() << "/" << a.denominator();
//	return os;
//}
#endif