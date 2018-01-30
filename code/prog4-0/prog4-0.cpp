#include<iostream>
#include <string>
using namespace std;

void test_c_str() {
	string s = "hello";
	char carr[10];
	strcpy(carr, s.c_str());
}
void type_deduction() {
	const int ci = 10;
	int i = 0;
	auto pc = &ci;
	//auto &rc = ci, *ptr = &i;
}
int main() {
	
}