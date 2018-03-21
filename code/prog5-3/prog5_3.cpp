#include <iostream>
using namespace std;

using pFun = double(*)(double);

double f_sphere(double x) {
	return x*x;
}
double f_default(double x) {
	return 0;
}
double f_sin(double x) {
	return sin(x);
}

double integrate(double l, double u, pFun pf = f_default, int n = 1000) {
	double sum = 0.0;
	double gap = (u - l) / n;  //ÿ������ĳ���
	for (int i = 0; i < n; i++)
		sum += (gap / 2.0) * (pf(l + i*gap) + pf(l + (i + 1)*gap));
	
	return sum;
}

int main() {
	cout<<"Ĭ�Ϻ���������[0:1]�ϵĻ���Ϊ��"<<integrate(0, 1) << endl;
	cout<<"Sphere����������[0:1]�ϵĻ���Ϊ��"<<integrate(0, 1, f_sphere)<<endl;
	cout<<"sin����������[0:1]�ϵĻ���Ϊ��"<<integrate(0, 1, f_sin)<<endl;
	return 0;
}