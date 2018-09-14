/*
*画出sin(x)在[0:2pi]内的曲线
*/
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main() {
	double step = 0.2;//x增加的步长
	double x = 0;//x从0开始
	while (x < 6.28) {//画一个周期的曲线
		int val = 30 * (sin(x) + 1);//计算sin(x)左侧的空格数
		for (int i = 0; i < val; ++i) {//画出所有空格
			cout << " ";
		}
		cout << "*" << endl;//在相应的位置打印*
		x += step;//处理下一个x
	}
	return 0;
}