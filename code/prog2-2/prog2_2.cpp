#include<iostream>
using namespace std;
int sum = 10;

int main() {
	cout << sum;     // 访问全局对象sum，输出10
	int sum = 0; 
	cout << sum << endl;//访问局部对象sum，输出0
	cout << ::sum;     // 访问全局对象sum，输出10
	return 0;
}