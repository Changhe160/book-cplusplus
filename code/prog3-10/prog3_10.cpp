/*
*ʯͷ��������Ϸ
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
			cout << "��ã� ʯͷ=0, ����=1, ��=2";
			computer = rand() % 3;
			cout << "����֣�";
			cin >> you;
			switch (computer){
			case 0:
				if (you == 1) 
					cout << "������!" << endl;
				else if (you==2) 
					cout << "��Ӯ��!" << endl;
				break;
			case 1:
				if (you == 2) 
					cout << "������!" << endl;
				else if (you == 0)
					cout << "��Ӯ��!" << endl;
				break;
			case 2:
				if (you == 0) 
					cout << "������!" << endl;
				else if (you == 1) 
					cout << "��Ӯ��!" << endl;
				break;
			}
		} while (computer==you);
		cout << "��Ҫ����Y/N:";
		char play;
		cin >> play;
		if (play == 'N' || play == 'n') break;
	}
	return 0;
}