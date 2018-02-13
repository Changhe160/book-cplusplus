/*
*计算30名学生数学科目平均成绩和标准差
*/
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
	srand(0);//使用固定种子，每次运行得到一样的结果，对于程序的调试是很重要的
    constexpr int sz = 30;
	int score[sz]; //定义一个数组，存放30个学生的成绩
	int mean = 0;//存放平均分数, 初始值必须为0
	for (auto &i : score) {//使用范围for语句访问，注意引用&不能丢
		i = 50 + rand() % 51;//成绩随机分布在50到100之间
		mean += i;//累加每一个学生成绩到mean里面
	}
	mean /= sz;//计算平均成绩
	double dev = 0;
	for (int i = 0; i < sz; ++i) {
		dev += pow(score[i] - mean, 2);//函数pow(x,a)计算 x^a
	}
	dev = sqrt(dev / sz);//计算标准差，函数sqrt(x)计算根号x
	cout << "平均成绩：" << mean << " 标准差：" << dev << endl;
	return 0;
}
