/*
*猜数字游戏, break, switch, do while
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0)); 
	int target = rand() % 100;
	int guess;
	cout << "请猜0-100之内的数" << endl;
	while(1) {
		cin >> guess;
		int val = (guess > target)- (guess < target);
		switch (val){
		case -1:
			cout << "猜小了" << endl;
			break;	//跳出switch
		case 1:
			cout << "猜大了" << endl;
			break;  //跳出switch
		case 0:
			cout << "恭喜！ 猜对了！" << endl;
			break;  //跳出switch
		}
		if (val == 0) {
			break; //跳出while
		}
	}
	return 0;




}