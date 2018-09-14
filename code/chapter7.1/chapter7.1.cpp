#include <iostream>
#include<string>
#include "Fraction.h"
using namespace std;

// 7.1 ��
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}

// 7.1.1 ��
template <typename T>
const T &getMax(const T &a, const T &b) {
	return a > b ? a : b;
}

// 7.1.2 ��
const double& getMax(const double &a, const double &b) {
	return a > b ? a : b;
}
bool operator>(const Fraction &lhs, const Fraction &rhs) {
	return lhs.m_numerator*rhs.m_denominator >
		lhs.m_denominator*rhs.m_numerator;
}

// 7.1.3 ��
template<typename T, int size>
const T& maxElem(T(&arr)[size]) {
	T *p = &arr[0];
	for (auto i = 0; i < size; ++i)
		if (*p < arr[i])
			p = &arr[i];
	return *p;
}

template <typename T>
T* const & getMax(T* const &a, T* const &b) {
	return *a>*b ? a : b;
}

template <>
const char* const &getMax(const char* const &a, const char* const &b) {
	return strcmp(a, b) > 0 ? a : b;
}

template<typename T>
void Swap(T &a, T &b) {
	T c(a);//���ƹ������c
	a = b;
	b = c;
}

template<>
void Swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// 7.1.4 ��
class X {
	void *m_p = nullptr;
public:
	template <typename T>
	void reset(T *t) { m_p = t; }
};

// 7.1.5 ��
template<typename... Args >
void foo(Args... args) {
	cout << sizeof...(args) << endl; //��ӡ������args�в����ĸ���
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
	os << t << " "; //��ӡ��һ������
	return print(os, rest...); //�ݹ����
}

template<typename T>
ostream& print(ostream &os, const T &t) {
	return os << t; //��ӡ���һ������
}

void rvalue(int &&val) {}
template<typename T>
void forwardValue(T &&val) {
	//rvalue(val); //����rvalue����������ֵ�β�
	rvalue(std::forward<T>(val));
}

template<typename... Args>
void fun(Args&&... args) {
	foo(std::forward<Args>(args)...);
}

void foo(const string &s, int &&i) {
	cout << s << i << endl;
}

int main() { 

	// 7.1.2 ��
	{
		cout << "7.1.2 �ڣ�" << endl;
		cout << getMax(1.0, 2.5) << endl; //TΪdouble

		cout << getMax<double>(1.0, 2.5) << endl; //��ʽָ��TΪdouble
		cout << getMax<string>("Hi ", "C++") << endl; //��ʽָ��TΪstring

		Fraction a(3, 4), b(2, 5);
		cout << getMax(a, b) << endl; //TΪFraction����
	}

	// 7.1.3 ��
	{
		cout << "7.1.3 �ڣ�" << endl;
		int arr[10] = { 1,8,5,3 };
		int x = maxElem(arr); //������ʽ����maxElem<int,10>(arr);

		int a = 1, b = 2;
		getMax(&a, &b);
		{
			const char* a = "Hi", *b = "C++";
			cout << getMax(a, b) << endl; //�����������汾�����Hi
		}
		int c = 1, d = 2;
		Swap(c, d);
		cout << c << " " << d << endl;
	}

	// 7.1.4 ��
	{
		cout << "7.1.4 �ڣ�" << endl;
		int i = 0;
		double d = 0;
		X x;
		x.reset(&i); //����x.reset<int>(&i);
		x.reset(&d); //����x.reset<double>(&d);
	}

	// 7.1.5 ��
	{
		cout << "7.1.5 �ڣ�" << endl;
		foo(); //�����0
		foo(1, 1.5); //�����2
		foo(1, 1.5, "C++"); //�����3

		print(cout, 1, 2.5, "C++") << endl; //���1 2.5 C++

		forwardValue(42); //���󣺲��ܽ�intת����int&&

		fun("abc", 42);
	}
}