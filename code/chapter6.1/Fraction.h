//������

#ifndef FRACTION__H
#define FRACTION__H
#include <iostream>
using namespace std;


//6.1.1
class Fraction {
	int m_numerator = 0;			// ����
	int m_denominator = 1;			//��ĸ
public:
	int numerator() const { return m_numerator; }
	int denominator() const { return m_denominator; }
	double value() const;			//�������ֵ
	void reduce();					//Լ��
	
	friend ostream& print(ostream &os, const Fraction &a);

private:
	int gcd(int x, int y); //����x��y�����Լ��
};

//6.1.2
inline double Fraction::value() const {
	return static_cast<double>(m_numerator) / m_denominator;
}

ostream& print(ostream &os, const Fraction &a);


#endif