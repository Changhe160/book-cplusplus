/*
*计算30名学生数学科目平均成绩和标准差
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int a2d[][2] = { 1,1,4 ,4,4};
	srand(0);
	constexpr int sz = 30;
	int score[sz];
	int mean = 0;
	for (auto &i:score) {
		i = 50+rand() % 50;
		mean += i;
	}
	mean /= sz;
	double dev = 0;
	for (int i = 0; i < sz; ++i) {
		dev+=pow(score[i]- mean,2);
	}
	dev = sqrt(dev / sz);
	cout << "平均成绩：" << mean <<" 标准差："<<dev<< endl;
	return 0;
}