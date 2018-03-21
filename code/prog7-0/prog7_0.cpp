#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

// 7.1 节
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}

// 7.1.1 节
template <typename T>
const T &getMax(const T &a, const T &b) {
	return a > b ? a : b;
}

// 7.1.2 节
const double& getMax(const double &a, const double &b) {
	return a > b ? a : b;
}
bool operator>(const Fraction &lhs, const Fraction &rhs) {
	return lhs.m_numerator*rhs.m_denominator >
		lhs.m_denominator*rhs.m_numerator;
}

// 7.1.3 节
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
const char* const &getMax(const char* const &a,
	const char* const &b) {
	return strcmp(a, b) > 0 ? a : b;
}

template<typename T>
void Swap(T &a, T &b) {
	T c(a);//复制构造对象c
	a = b;
	b = c;
}

template<>
void Swap(int &a, int &b) {  
	a ^= b;
	b ^= a;
	a ^= b;
}

// 7.1.4 节
class X {
	void *m_p = nullptr;
public:
	template <typename T>
	void reset(T *t) { m_p = t; }
};

// 7.1.5 节
template<typename... Args >
void foo(Args... args) {
	cout << sizeof...(args) << endl; //打印参数包args中参数的个数
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
	os << t << " "; //打印第一个参数
	return print(os, rest...); //递归调用
}

template<typename T>
ostream& print(ostream &os, const T &t) {
	return os << t; //打印最后一个参数
}

void rvalue(int &&val) {}
template<typename T>
void forwardValue(T &&val) {
	//rvalue(val); //错误：rvalue函数接受右值形参
	rvalue(std::forward<T>(val));
}

template<typename... Args>
void fun(Args&&... args) {
	foo(std::forward<Args>(args)...);
}

void foo(const string &s, int &&i) {
	cout << s << i << endl;
}

// 7.2.3 节
template<typename T>
struct Less {
	bool operator()(const T &a, const T &b) {
		return a < b;
	}
};

// 7.2 节 and 7.3.1 节
template<typename T, size_t N = 10>
class Array {
	T m_ele[N];
public:
	Array() {}
	Array(const std::initializer_list<T> &);
	T& operator[](size_t i);
	constexpr size_t size() { return N; }
	template<typename F = Less<T> > //成员模板参数F具有默认值Less<T>
	void selectionSort(F f = F()); //选择排序
	template<typename F = Less<T> >
	void insertionSort(F f = F()); //插入排序
	template<typename F = Less<T> >
	void bubbleSort(F f = F()); //冒泡排序

	int binarySearch(const T &, int left = 0, int right = N - 1);
private:
	void swap(int i, int j) {
		T t = m_ele[i];
		m_ele[i] = m_ele[j];
		m_ele[j] = t;
	}
};

// 7.2.1 节
template<typename T, size_t N>
Array<T, N>::Array(const std::initializer_list<T> &l) :m_ele{ T() } {
	size_t m = l.size() < N ? l.size() : N;
	for (size_t i = 0; i < m; ++i) {
		m_ele[i] = *(l.begin() + i);
	}
}

template<typename T, size_t N>
T& Array<T, N>::operator[](size_t i) {
	return m_ele[i];
}

// 7.3.1 节
template<typename T, size_t N>
template<typename F >
void Array<T, N>::selectionSort(F f) {
	for (int i = 0; i < N - 1; ++i) {
		int min = i; // 记录待排序数据中最小元素位置
		for (int j = i + 1; j < N; ++j) {
			if (f(m_ele[j], m_ele[min]))
				min = j; //更新最小元素位置	
		}
		swap(i, min); //把最小元素放到位置i
	}
}

template<typename T, size_t N>
template<typename F >
void  Array<T, N>::insertionSort(F f) {
	for (int i = 1, j; i < N; ++i) {
		// a temporary copy of the current element
		T t = m_ele[i];

		// find the position for insertion
		for (j = i; j > 0; --j) {
			if (f(m_ele[j - 1], t))
				break;
			// shift the sorted part to right
			m_ele[j] = m_ele[j - 1];
		}

		// insert the current element
		m_ele[j] = t;
	}
}

template<typename T, size_t N>
template<typename F >
void  Array<T, N>::bubbleSort(F f) {
	for (int i = N - 1; i >= 0; --i) {
		// bubble up
		for (int j = 0; j <= i - 1; ++j)
		{
			if (f(m_ele[j + 1], m_ele[j]))
				swap(j, j + 1);
		}
	}
}

// 7.3.2 节
template<typename T, size_t N>
int Array<T, N>::binarySearch(const T &value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (m_ele[middle] == value)
			return middle;
		else if (m_ele[middle] > value)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}
/***********/


int main() {
	// 7.1.2 节
	{
		cout << "7.1.2 节：" << endl;
		cout << getMax(1.0, 2.5) << endl; //T为double

		cout << getMax<double>(1.0, 2.5) << endl; //显式指明T为double
		cout << getMax<string>("Hi ", "C++") << endl; //显式指明T为string

		Fraction a(3, 4), b(2, 5);
		cout << getMax(a, b) << endl; //T为Fraction类型
	}

	// 7.1.3 节
	{
		cout << "7.1.3 节：" << endl;
		int arr[10] = { 1,8,5,3 };
		int x = maxElem(arr); //或者显式调用maxElem<int,10>(arr);

		int a = 1, b = 2;
		getMax(&a, &b);
		{
			const char* a = "Hi", *b = "C++";
			cout << getMax(a, b) << endl; //调用特例化版本，输出Hi
		}
		int c = 1, d = 2;
		Swap(c, d);
		cout << c << " " << d << endl;
	}

	// 7.1.4 节
	{
		cout << "7.1.4 节：" << endl;
		int i = 0;
		double d = 0;
		X x;
		x.reset(&i); //或者x.reset<int>(&i);
		x.reset(&d); //或者x.reset<double>(&d);
	}

	// 7.1.5 节
	{
		cout << "7.1.5 节：" << endl;
		foo(); //输出：0
		foo(1, 1.5); //输出：2
		foo(1, 1.5, "C++"); //输出：3

		print(cout, 1, 2.5, "C++") << endl; //输出1 2.5 C++

		forwardValue(42); //错误：不能将int转化成int&&

		fun("abc", 42);
	}
	
	// 7.2.2 节
	{
		cout << "7.2.2 节：" << endl;
		Array<char, 5> a; //创建一个Array<char, 5>类型对象a
		Array<int, 5> b = { 1,2,3 }; //创建一个Array<int, 5>类型对象b
		for (int i = 0; i < b.size(); ++i)
			cout << b[i] << " ";
		cout << endl;
	}

	// 7.2.3 节
	{
		cout << "7.2.3 节：" << endl;
		Array<int> a = { 2,1,3 }; //a的默认元素个数为10
		Array<int, 5> b; //指定b的元素数目为5
		a.bubbleSort(); //采用默认的比较方式对a 中元素进行排序
		for (int i = 0; i < a.size(); ++i)
			cout << a[i] << " ";
	}
	system("pause");
	return 0;
}


