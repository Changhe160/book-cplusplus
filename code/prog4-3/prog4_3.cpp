/*
*制作扫雷小游戏地图
*/
#include <cstdlib>
#include <iostream>
#include<ctime>
using namespace std;

int main() {
	srand(time(0));//
	constexpr int sz = 8;
	char map[sz][sz];
	for (auto &row : map) {
		for (auto &col : row) {
			int num = rand() % 100;
			if (num <= 50) //设置一个地雷
				col = '*';			
			else 
				col = '0';		
		}
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (map[i][j] != '*') continue;
			if (i + 1 < sz && map[i + 1][j] != '*') map[i + 1][j] += 1;
			if (i - 1 >= 0 && map[i - 1][j] != '*') map[i - 1][j] += 1;
			if (j + 1 < sz && map[i][j + 1] != '*') map[i][j + 1] += 1;
			if (j - 1 >= 0 && map[i][j - 1] != '*') map[i][j - 1] += 1;
		}
	}
	
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}

	for (auto p = &map[0][0]; p < map[0] + sz*sz; ++p) {
		if ((p - &map[0][0]) % sz == 0) cout << endl;
		cout << *p << " ";
	}
	return 0;
}