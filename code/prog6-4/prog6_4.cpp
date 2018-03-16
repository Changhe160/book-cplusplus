#include<string>
#include<iostream>

using namespace std;
class PartTimeWorker {
	string m_name;//员工姓名；
	double m_hours;//工作小时数；
	static double ms_payRate;//小时工资；
public:
	double salary() {		return m_hours*ms_payRate;	}
	friend ostream& operator<<(ostream &o, PartTimeWorker& w);
};
//静态成员的初始化；
double PartTimeWorker::ms_payRate = 7.53;


ostream& operator<<(ostream &o, PartTimeWorker& w) {
	string PartTimeWorker::*p1 = &PartTimeWorker::m_name;
	auto p2 = &PartTimeWorker::m_name;
	

	PartTimeWorker *w2 = &w;
	cout << w.m_name << endl;
	o << w.*p1 << endl;
	o << w2->*p2 << endl;
	
	return o;
}
int main() {
	
	double (PartTimeWorker::*pf)();
	pf = &PartTimeWorker::salary;//成员函数指针；

	auto pf2= &PartTimeWorker::salary;

	using PTWS= double (PartTimeWorker::*)();

	PTWS pf3= &PartTimeWorker::salary;

	PartTimeWorker w;

	cout << w.salary() << endl;//普通访问方式；
	cout << (w.*pf)() << endl;//成员函数指针访问方式
	cout << (w.*pf2)() << endl;//成员函数指针访问方式



}

