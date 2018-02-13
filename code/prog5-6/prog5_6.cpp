/*
*递归方法求解八皇后问题
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool isSafe(int i, const vector<int> &que) {//第i行皇后是否安全
	for (int k = 0; k < i; ++k) {//依次检查是否与第0行到第i-1行的皇后冲突
		if (que[k] == que[i] || (abs(que[i] - que[k]) == abs(i - k)))
			return false;

	}
	return true;
}
void queen(int i, vector<int> &que, int &cnt) {//放置第i行皇后
	if (i == 8) {//打印新的方案
		cout << "方案" << ++cnt << ":";
		for (int k = 0; k < que.size(); ++k)
			cout << que[k];
		cout << endl;
		return; //回溯寻找下一个可行方案
	}
	for (int k = 0; k < que.size(); ++k) {
		que[i] = k; //第i行的皇后放置在第k列
		if (isSafe(i, que)) //如果安全，安排下一行皇后
			queen(i + 1, que, cnt);
	}
}
int main() {
	vector<int> que(8); //存放每一行皇后的位置，初始值为0
	int cnt = 0; //找到的方案数目
	queen(0, que, cnt);
	return 0;
}
