/*
*猜数字游戏
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(){
	srand(time(0)); // use current time as seed for random generator
	int target = rand() % 100;
	int guess;
	cout << "请猜0-100之内的数" << endl;
	do {
		cin >> guess;
		if (guess < target) {
			cout << "猜小了" << endl;
		}
		else if(guess > target) {
			cout << "猜大了" << endl;
		}
		else {
			cout << "恭喜！ 猜对了！" << endl;
		}
	} while (guess != target);
	return 0;
}