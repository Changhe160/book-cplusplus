/*
*��Ǯ��ټ�����
*/
#include <iostream>
using namespace std;

int main() {
	int max_rst=10, max_hen;
	max_rst = 100 / 5;
	max_hen = 100 / 3;
	for (int i = 0; i < max_rst; ++i) {
		for (int j = 0; j < max_hen; ++j) {
			int k = 100 - i - j;
			if (k % 3) continue;
			if (5 * i + 3 * j + k / 3 == 100) {
				cout << "������" << i << " ĸ����" << j << " С����" << k << endl;
			}
		}
	}
	return 0;
}