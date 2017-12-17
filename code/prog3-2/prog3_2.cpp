/*
*将百分制的学生成绩转换成五级制，如果成绩在90分到100分范围内（包括90分和100分），
*则转换成A，80分到90分范围内为 B（包括80分不包括90分），依次类推，60分以下为F
*/
#include<iostream>
using namespace std;

int main() {
	unsigned score;
	cout << "请输入一个分数:";
	cin >> score;

	if (score < 60) {
		cout << "F" << endl;
	}
	else if (score < 70) {
		cout << "D" << endl;
	}
	else if (score < 80) {
		cout << "C" << endl;
	}
	else if (score < 90) {
		cout << "B" << endl;
	}
	else {
		cout << "A" << endl;
	}
	
	return 0;
}