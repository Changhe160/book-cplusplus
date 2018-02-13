#include <iostream>
#include <cmath>  // 使用sin函数
using namespace std;

using pFun = double(*)(double);

double f_sphere(double x) {
	return x*x;
}
double f_default(double x) {
	return 0;
}

double integrate(double l, double u, pFun pf = f_default, int n = 1000) {
	double sum = 0.0;
	double gap = (u - l) / n;  //每个间隔的长度
	for (int i = 0; i < n; i++)//累加每个梯形的面积
		sum += (gap / 2.0) * (pf(l + i*gap) + pf(l + (i + 1)*gap));

	return sum;
}

int main() {
	cout << "默认函数在区间[0:1]上的积分为：" << integrate(0, 1) << endl;
	cout << "Sphere函数在区间[0:1]上的积分为：" << integrate(0, 1, f_sphere) << endl;
	cout << "sin函数在区间[0:1]上的积分为：" << integrate(0, 1, sin) << endl;
	return 0;
}
