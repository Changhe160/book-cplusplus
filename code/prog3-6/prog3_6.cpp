/*
*输入一段文本统计数字字符的个数
*/
#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	char x;
	do {
		x = cin.get();
		if (x >= '0'&&x <= '9') ++cnt;
	} while (x != EOF);

	cout << "数字字符个数为： " << cnt << endl;
	return 0;
}