#include<string>
#include<iostream>

using namespace std;

/*
class PartTimeWorker{
	
	string m_name;
	double m_hours;
	static double ms_payRate;
	static const int ms_maxHourWeek = 20;
public:
	double salary();
	static double rate() {
		return ms_payRate;
	}
	static void initRate(double rate);
};
double PartTimeWorker::ms_payRate = 7.53;

double PartTimeWorker::salary() {
	return m_hours*ms_payRate;
}

void PartTimeWorker::initRate(double rate) {
	ms_payRate = rate;
}

using FP = void(*)(int);
FP b(int, FP) {
	FP f=nullptr;
	return f;
}

void(*c(int, void(*fp)(int)))(int){
	FP f= nullptr;
	return f;
}


template<typename T, typename... Args>
ostream &print(ostream *os, const T &t, const Args&... rest) {
	os << t",";
	return print(os, rest...);
}
*/

template<typename T, int size> 
const T & getMax(T(&arr)[size]) {
	T *p = &arr[0];
	for (auto i = 0; i < size; ++i) {
		if (*p < arr[i])
			p = &arr[i];
	}
	return *p;
}
template<typename T>
T add(const T &a, const T &b) {
	return a+b;
}

template<>
const char* add(const char* const &a, const char * const &b) {
	return 0;
}

template<typename T>
T add(const T*  &a, const T*  &b) {
	return *a + *b;
}

template<typename T>
const T& getMax(const T &a, const T &b) {
	return a>b?1:0;
}

template<typename T>
 T* const& getMax( T* const &a,   T* const &b) {
	return *a>*b ? a : b;
}

template<>
const char *const & getMax(const char* const &a, const char* const &b) {
	return  strcmp(a,b)>0?a:b;
}

const string & max(const string & s1, const string& s2) {
	return s1 > s2 ? s1 : s2;
}

struct X
{
	template <class T> 
	void mf(T* t) { m_p = t; }
	void *m_p=nullptr;
};


int main() {


	int i;
	X* x = new X();
	x->mf<int>(&i);


	max("HI", "c++");

	const char* const a = "Hi ", *const b = "C++";
	const char* c = "Hi", *d = "C++";
	int i1=0, i2 = 0;


	//compare(a, b);
	//compare(c, d);

	cout<<getMax(c, d)<<endl;
	//cout << getMax("Hi", "C++") << endl;
	getMax(&i1, &i2);
	//cout << add<string>("Hi ", "C++") << endl;
	//cout << add(a,b) << endl;
	//int c = 1, d = 2;
	//cout<<add(&c, &d);

}
