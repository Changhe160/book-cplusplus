/*
找出10到1000之内的所有回文数
*/
#include<iostream>
#include<vector>
using namespace std;
bool is_palindrome(int x);//函数声明
int main() {
	for (int i = 10; i <= 1000; ++i) {
		if (is_palindrome(i))
			cout << i << endl;
	}
	return 0;
}
bool is_palindrome(int x) {
	vector<int> digit;//存放x的每一位数字
	while (x != 0) {
		digit.push_back(x % 10); //获取当前x的个位数，并将其尾插到digit
		x /= 10;//去掉x的个位数
	}
	for (int i = 0, j = digit.size() - 1; i < j; ++i, --j) {
		if (digit[i] != digit[j])
			return false;
	}
	return true;
}
