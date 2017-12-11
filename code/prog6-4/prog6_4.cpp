#include<string>
#include<iostream>

using namespace std;
class PartTimeWorker {
	string m_name;
	double m_hours;
	static double ms_payRate;
public:
	double salary() {		return m_hours*ms_payRate;	}
	friend ostream& operator<<(ostream &o, PartTimeWorker& w);
};
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
	pf = &PartTimeWorker::salary;

	auto pf2= &PartTimeWorker::salary;

	using PTWS= double (PartTimeWorker::*)();

	PTWS pf3= &PartTimeWorker::salary;

	PartTimeWorker w;
	cout << w.salary() << endl;
	cout << (w.*pf)() << endl;
	cout << (w.*pf2)() << endl;

}

