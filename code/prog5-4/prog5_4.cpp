#include<iostream>

int sumTo(int i) {
	if (i == 0) return 0;
	return 	sumTo(i - 1) + i;
}
int main() {
	std::cout << sumTo(3);
	return 0;
}
