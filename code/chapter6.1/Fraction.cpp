#include "Fraction.h"

//6.1.2
inline double Fraction::value() const {
	return static_cast<double>(m_numerator) / m_denominator;
}

void Fraction::reduce(){
	int num= gcd(m_numerator, m_denominator);
	m_denominator /= num;
	m_numerator /= num;
}
//6.1.3
int Fraction::gcd(int x, int y)
{
	if (y == 0)
		return x; //base case,return x when y equals 0
	else 
		gcd(y, x%y); //recursive call by using arithmetic rules
	return 0;
}


