/*
*判断一个整数是否大于0且是3的倍数
*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "请输入整数n:";
	cin >> n;
	if (n > 0 && n % 3 == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}