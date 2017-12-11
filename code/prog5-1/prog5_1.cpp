/*
找出10到1000之内的所有回文数
*/
#include<iostream>
#include<vector>
using namespace std;
bool is_palindrome(int x);

int main(int argc, char * argv[]) {
	for (int i = 10; i <= 1000; ++i) {
		if (is_palindrome(i))
			cout << i << endl;
	}
	return 0;
}

bool is_palindrome(int x) {
	vector<int> digit;
	while (x != 0){
		digit.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0, j = digit.size() - 1; i < j; ++i, --j) {
		if (digit[i] != digit[j]) 
			return false;
	}
	return true;
}