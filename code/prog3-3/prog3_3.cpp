/*
*求解一元二次方程的根
*/
#include<iostream>
#include<cmath>  //用于求平方根函数sqrt
using namespace std;

int main() {
	double a,b,c;
	cout << "请输入a(a!=0),b,c:";
	cin >> a >> b >> c;
	if (a != 0) { //方程
		double delta = b*b - 4 * a*c;
		if (delta > 0) {
			double x1, x2;
			delta = sqrt(delta);
			x1 = (-b + delta) / (2 * a);
			x2 = (-b - delta) / (2 * a);
			cout << "方程有两个实根,分别为：" << x1 << ", " << x2 << endl;
		}
		else if (delta < 0) {
			cout << "方程无实根" << endl;
		} 
		else {
			cout << "方程有两个相同的实根：" << -b / (2 * a) << endl;
		}
	}
	else {
		cout << "a不能为0" << endl;
	}

	return 0;
}