/*
*制作扫雷小游戏地图
*/
#include <cstdlib>
#include <iostream>
#include<ctime>
using namespace std;
int main() {
	srand(time(0));
	constexpr int sz = 8;
	char map[sz][sz];
	for (auto &row : map) {//每个元素的引用
		for (auto &col : row) {//内嵌数组中每个元素的引用
			int num = rand() % 100;
			if (num <= 40) //以0.4的概率设置每个方格的地雷
				col = '*';
			else
				col = '0'; //没有地雷的方格初始化为字符0
		}
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (map[i][j] != '*')
				continue;//跳过地雷的方格
			if (i + 1 < sz && map[i + 1][j] != '*') map[i + 1][j] += 1;
			if (i - 1 >= 0 && map[i - 1][j] != '*') map[i - 1][j] += 1;
			if (j + 1 < sz && map[i][j + 1] != '*') map[i][j + 1] += 1;
			if (j - 1 >= 0 && map[i][j - 1] != '*') map[i][j - 1] += 1;
		}
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;

	}
	return 0;

}
