/*
*石头剪刀布游戏
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int computer,you;
	while (1) {
		do {
			cout << "你好！ 石头=0, 剪刀=1, 布=2";
			computer = rand() % 3;
			cout << "请出手：";
			cin >> you;
			switch (computer){
			case 0:
				if (you == 1) 
					cout << "你输了!" << endl;
				else if (you==2) 
					cout << "你赢了!" << endl;
				break;
			case 1:
				if (you == 2) 
					cout << "你输了!" << endl;
				else if (you == 0)
					cout << "你赢了!" << endl;
				break;
			case 2:
				if (you == 0) 
					cout << "你输了!" << endl;
				else if (you == 1) 
					cout << "你赢了!" << endl;
				break;
			}
		} while (computer==you);
		cout << "还要玩吗？Y/N:";
		char play;
		cin >> play;
		if (play == 'N' || play == 'n') break;
	}
	return 0;
}