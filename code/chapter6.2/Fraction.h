/*
������
*/

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;

class Fraction{
	int m_numerator;				// ����
	int m_denominator;				//��ĸ
public:
	Fraction(int a=0,int b=1);		//Ĭ�ϵĹ��캯��
	Fraction(const Fraction& rhs);		//�������캯��
	~Fraction() {
		cout << "des" << endl;
	}

	Fraction& operator=(const Fraction&);//����=�����
	Fraction& operator+=(const Fraction&);	// ���������, ע�ⷵ��ֵ����Ϊ����
	Fraction& operator*=(const Fraction&);	// ���������

	Fraction operator+(const Fraction&) const;	// ���������
	Fraction operator-(const Fraction&)const;	// ���������
	Fraction operator*(const Fraction&)const;	// ���������
	Fraction operator/(const Fraction&)const;	// ���������

	bool operator==(const Fraction&)const;	// ��������ȱȽ�
	bool operator<(const Fraction&)const;	// ������С�ڱȽ�
	bool operator>(const Fraction&)const;//���������ڱȽ�
	bool operator==(double)const;	// ��ʵ����ȱȽ�
	bool operator<(double)const;
	bool operator>(double)const;

	Fraction reciprocal();			// ����
	void reduction();				//Լ��

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