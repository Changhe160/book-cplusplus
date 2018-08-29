#include "Fraction.h"
#include <complex>
Fraction divide(Fraction dividend, Fraction divisor) {
	Fraction result(dividend.denominator(), divisor.numerator());
	return result;
}
Fraction operator/(const Fraction &dividend, const Fraction &divisor) {
	Fraction result(dividend.denominator(), divisor.numerator());
	return result;
}

template<typename T, int i>
class fun{
public:
	void foo();
};
template<typename T, int i>
void fun<T, i>::foo() {

}
int main(){

	std::complex<double> c;
	Fraction f1 = 5;
	
	f1*=4;

	Fraction f2(2,3);
	Fraction f3 = divide(f1, f2);
	f1.reduce();
	f1(4, 5);
	f1 = f2 / f3;

	cout << f1 << " " << f2 << endl;
	return 0;
}