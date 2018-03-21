/*
*冒泡排序法
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
		for (int j = score.size()-1; j >i; --j) {//每一轮冒泡过程将最小的数浮出来
			if (score[j] < score[j-1])//相邻的两个数比较，从下向上冒泡
				swap(score[j], score[j-1]);
		}
	}
	for (auto &i : score)
		cout << i << endl;
		
	return 0;
}