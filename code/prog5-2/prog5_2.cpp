/*
*ð������
*/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

inline void swap(int & x, int &y) {
	int z(x);
	x = y;
	y = z;
}
int main() {
	srand(0);
	vector<int> score(10);
	for (auto &i : score)
		i = rand() % 100;
	for (int i = 0; i < score.size() - 1; ++i) {
		for (int j = score.size()-1; j >i; --j) {//ÿһ��ð�ݹ��̽���С����������
			if (score[j] < score[j-1])//���ڵ��������Ƚϣ���������ð��
				swap(score[j], score[j-1]);
		}
	}
	for (auto &i : score)
		cout << i << endl;
		
	return 0;
}