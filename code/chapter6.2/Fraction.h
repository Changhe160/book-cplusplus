/*
分数类
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator;				// 分子
	int m_denominator;				//分母
public:
	Fraction(int a=0,int b=1);		//默认的构造函数
	Fraction(const Fraction& rhs);		//拷贝构造函数
	~Fraction() {
		cout << "des" << endl;
	}

	Fraction& operator=(const Fraction&);//重载=运算符
	Fraction& operator+=(const Fraction&);	// 两分数相加, 注意返回值类型为引用
	Fraction& operator*=(const Fraction&);	// 两分数相乘

	Fraction operator+(const Fraction&) const;	// 两分数相加
	Fraction operator-(const Fraction&)const;	// 两分数相减
	Fraction operator*(const Fraction&)const;	// 两分数相乘
	Fraction operator/(const Fraction&)const;	// 两分数相除

	bool operator==(const Fraction&)const;	// 两分数相等比较
	bool operator<(const Fraction&)const;	// 两分数小于比较
	bool operator>(const Fraction&)const;//两分数大于比较
	bool operator==(double)const;	// 和实数相等比较
	bool operator<(double)const;
	bool operator>(double)const;

	Fraction reciprocal();			// 求倒数
	void reduction();				//约分

	double getValue() const{
		return static_cast<double>(m_numerator) / m_denominator;
	}
	int getNumerator() const {
		return m_numerator;
	}
	int getDenorminator() const {
		return m_denominator;
	}

private:
	int gcd(int x, int y);

	friend void makeCommon(Fraction &a, Fraction &b);
	friend ostream &operator<<(ostream & out, const Fraction& f);
};
#endif