#include<iostream>
int main() {
	int sum = 10;
	{
		int sum = 0;
		std::cout << sum << std::endl;//访问第二个sum，输出0
	}
	std::cout << sum << std::endl;     // 访问第一个sum，输出10	
	return 0;
}