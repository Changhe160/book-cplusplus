#include "Array.h"
#include <iostream>
#include<memory>
#include<utility>
#include<string>
using namespace std;

template<typename... Args>
void foo(Args... args) {
	cout << sizeof...(args)<<endl;
}

template<typename T>
ostream& print(ostream & os, const T &t) {
	return os << t;
}

template<typename T, typename... Args>
ostream& print(ostream & os, const T &t, const Args&... rest) {
	os << t << " ";
	return print(os, rest...);
}

void work(const string &s, int &&i) {
	cout << s << i<<endl;
}

template<typename... Args>
void fun(Args&&... args) {
	work(std::forward<Args>(args)...);
}


void memoryleak(int i) {
	int *p = new int(1), *q=new int(2);

	if (*p > i) return;
	delete p;

	q = &i;
	delete q;
}

void rvalue(int &&val) {
	
}

template<typename T>
void forwardValue( T &&val) {
	//rvalue(val);
	rvalue(std::forward<T>(val));
}
void smartpointer() {
	//unique_ptr<int> p1 (new int());
	//shared_ptr<int> p1 = new int(1024);//error：必须使用直接初始化的形式
	shared_ptr<int> p2(new int(1024));
	cout<<p2.use_count()<<endl;
	auto p3=p2;
	cout << p3.use_count() << endl;
	auto p4 = make_shared<int>(11), p5(p4); 
	p4 = p3;
	cout << p3.use_count() <<" "<< p5.use_count()<< endl;

	weak_ptr<int> p6(p5);
	if (auto p7=p6.lock()) {
		cout << *p7 << endl;
	}
	cout << p3.use_count() << " " << p5.use_count() << endl;
}

template<typename T>
void Swap(T &a, T &b) {
	T c(a);
	a = b;
	b = c;
}

template<>
void Swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main() { 
	forwardValue(42);

	fun("abc", 42);
	/*	smartpointer();
	foo();
	foo(1, 2.0);
	foo(1, 2.5, "sd");

	print(cout,1, 2.5, "sd")<<endl;

	Array<int,7> a = { 38, 27, 43,  3,  9, 82, 10 };
	
	//a.selectionSort();
	a.insertionSort();
	//a.bubbleSort();
	for (auto i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
	cout << a.binarySearch(96);
	return 0;*/
}