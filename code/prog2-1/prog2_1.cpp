#include<iostream>
using namespace std;

int main() {
	int sum = 0; //用于存放两个数的和
	{
		int val1 = 10, val2 = 10;
		sum = val1 + val2;
	}
	cout << sum;
	return 0;
}