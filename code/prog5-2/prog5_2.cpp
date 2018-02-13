/*
*冒泡排序法
*/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
inline void Swap(int & x, int &y) {
	int z(x);
	x = y;
	y = z;
}
int main() {
	srand(0);
	vector<int> score(10);
	for (auto &i : score)//随机生成学生成绩
		i = rand() % 100;
	for (int i = 0; i < score.size() - 1; ++i) {//进行score.size()-1轮操作
		for (int j = score.size() - 1; j >i; --j) {//每一轮将最小的数浮出来
			if (score[j] < score[j - 1])//相邻的两个数比较，从下向上冒泡
				swap(score[j], score[j - 1]);//相邻的两个数比较，小的数向上浮
		}
	}
	for (auto &i : score)
		cout << i << endl;

	return 0;
}
