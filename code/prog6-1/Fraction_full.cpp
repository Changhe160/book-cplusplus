#include "Fraction.h"

void Fraction::reduction(){
	int num= gcd(m_numerator, m_denominator);
	m_denominator /= num;
	m_numerator /= num;
}

int Fraction::gcd(int x, int y)
{
	if (y != 0)
		gcd(y, x%y); //recursive call by using arithmetic rules
	else 
		return x; //base case,return x when y equals 0
}

Fraction::Fraction(int a,int b):m_numerator(a),m_denominator(b){

}
Fraction::Fraction(const Fraction& rhs):m_numerator(rhs.m_numerator),m_denominator(rhs.m_denominator){
	
}
Fraction& Fraction::operator=(const Fraction& rhs){
	if(&rhs==this) return *this;   //do not assign itself, e.g. a=a;

	m_numerator=rhs.m_numerator;
	m_denominator=rhs.m_denominator;
	return *this;
}

Fraction Fraction::operator+(const Fraction&rhs)const{ // do not change *this and rhs	
	int numerator = m_numerator*rhs.m_denominator + m_denominator*rhs.m_numerator;
	int denominator = m_denominator*rhs.m_denominator;
	return Fraction(numerator, denominator);
	//Fraction f(numerator, denominator);
	//return f;
}
Fraction Fraction::operator-(const Fraction&rhs)const {
	int numerator = m_numerator*rhs.m_denominator - m_denominator*rhs.m_numerator;
	int denominator = m_denominator*rhs.m_denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator*(const Fraction&rhs)const {
	return Fraction(m_numerator*rhs.m_numerator,m_denominator*rhs.m_denominator); 
}
Fraction Fraction::operator/(const Fraction&rhs)const{
	return Fraction(m_numerator*rhs.m_denominator,m_denominator*rhs.m_numerator); 
}

Fraction& Fraction::operator+=(const Fraction&rhs){// Note the differences with operator +()
	m_numerator = m_numerator*rhs.m_denominator + m_denominator*rhs.m_numerator;
	m_denominator = m_denominator*rhs.m_denominator;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction&rhs){
	m_numerator*=rhs.m_numerator;
	m_denominator*=rhs.m_denominator;
	return *this;
}

Fraction Fraction::reciprocal(){
	return Fraction(m_denominator,m_numerator); 
}
bool Fraction::operator==(const Fraction&rhs)const{
	if(this->operator/(rhs)==1) return true; //please debug this line code 
	return false;
}
bool Fraction::operator<(const Fraction&rhs)const{
	if(this->operator/(rhs)<1) return true;
	return false;
}
bool Fraction::operator>(const Fraction&rhs)const{
	if(this->operator/(rhs)>1) return true;
	return false;
}

bool Fraction::operator==(double real)const {
	if(m_numerator*1./m_denominator==real) return true;	
	return false;
}
bool Fraction::operator<(double real)const {
	if(m_numerator*1./m_denominator<real) return true;	
	return false;
}	
bool Fraction::operator>(double real)const {
	if(m_numerator*1./m_denominator>real) return true;	
	return false;
}

 ostream &operator<<( ostream & out, const Fraction& f) {
	out<< f.m_numerator << "/" << f.m_denominator;
	return out;
}

 void makeCommon(Fraction &a, Fraction &b) {
	 int den = a.m_denominator;
	 a.m_numerator *= b.m_denominator;

	 b.m_denominator = a.m_denominator *= b.m_denominator;
	 b.m_numerator *= den;
 }