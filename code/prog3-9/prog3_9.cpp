/*
*画出sin(x)在[0:2pi]内的曲线
*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main() {
	double step = 0.2;//x增加的步长
	double x = 0;
	ofstream out("sinx.txt");
	while (x < 6.28) {//画一个周期的曲线
		int val = 60*(sin(x)+1)/2;
		for (int i = 0; i < val; ++i) {
			cout << " ";
			out << "~";
		}
		cout << "*" << endl;
		out << "*\\\\" << endl;
		x += step;
	}
	out.close();
	return 0;
}