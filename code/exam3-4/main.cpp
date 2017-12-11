/*
*将百分制的学生成绩转换成五级制，如果成绩在90分到100分范围内（包括90分和100分），
*则转换成A，80分到90分范围内为 B（包括80分不包括90分），依次类推，60分以下为F
*/
#include<iostream>
using namespace std;

int main() {
	int score;
	cout << "请输入一个分数:";
	cin >> score;

	switch (score/10){
	case 9:case 10:
		cout << "A" << endl;
		break;
	case 8:
		cout << "B" << endl;
		break;
	case 7:
		cout << "C" << endl;
		break;
	case 6:
		cout << "D" << endl;
		break;
	default:
		cout << "F" << endl;
		break;
	}	
	return 0;
}