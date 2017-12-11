/*
*输入一段文本统计数字字符的个数
*/
#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	char digit;
	do {
		digit = cin.get();
		if (digit >= '0'&&digit <= '9') ++cnt;
	} while (digit != EOF);

	cout << "数字字符个数为： " << cnt << endl;
	return 0;
}