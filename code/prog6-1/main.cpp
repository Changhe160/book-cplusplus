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

bool operator>(const Fraction &lhs, const Fraction &rhs){
	return lhs.m_numerator*rhs.m_denominator > lhs.m_denominator*rhs.m_numerator;
}


template<typename T, int i>
class fun{
public:
	void foo();
};
template<typename T, int i>
void fun<T, i>::foo() {

}

template <typename T>
const T& getMax(const T &a, const T &b) {
	return a > b ?	a :	b;
}

int main(){
	//Fraction f1 = 5;
	Fraction f1(4,8),f2(3,7);
	//double x = 1.0 + f1;
	//int i = f1;
	makeCommon(f1, f2);
	//getMax(f1, f2);

	/*f1.reduce();
	cout << f1;

	Fraction f2(2,3);
	Fraction f3 = divide(f1, f2);
	f1.reduce();
	f1(4, 5);
	f1 = f2 / f3;

	cout << f1 << " " << f2 << endl;*/
	return 0;
}