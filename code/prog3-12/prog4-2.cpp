/*
*八皇后问题
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void findall() {
	constexpr int sz = 8;
	int que[sz] = { 0 };
	int i = 0, cnt = 0;
	sqrt(1.2);
	while (i >= 0) {
		int k = 0;
		while (k<i) {
			if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k))) {
				++k;
			}
			else {
				break;
			}
		}

		if (k < i || que[i] == 8) {//有冲突或者搜索下一个方案时最后一行出界

			++que[i];//移动到下一列

			while (que[i] >= 8) {//当前行所有尝试都失败，需要回溯
				que[i] = 0; //重置当前行皇后位置
				--i;//回溯到上一行
				if (i < 0) {//如果回溯到第0行之前，结束运行
					break;
				}
				++que[i];//前一行皇后后移一列				
			}

			continue; //从新检测是否与前面所有皇后冲突

		}
		else { //无冲突，安排下一排皇后
			++i;
			if (i < sz) continue; 	//否则找到一个方案并输出

			cout << "方案" << ++cnt << ": ";
			for (k = 0; k<sz; ++k) {
				cout << que[k];
			}
			cout << endl;

			i = sz - 1; //
			++que[i];
		}
	}

}

void onesolution() {
	constexpr int sz = 8;
	int que[sz] = { 0 };
	int i = 0;
	while (i >= 0) {
		int k = 0;
		while (k<i) {
			if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k))) {
				++k;
			}
			else {
				break;
			}
		}
		if (k < i) {//有冲突
			++que[i];//移动到下一列
			while (que[i] == 8) {//当前行所有尝试都失败，需要回溯
				que[i] = 0; //重置当前行皇后位置
				--i;//回溯到上一行
				if (i < 0) {//如果回溯到第0行之前，结束运行
					break;
				}
				++que[i];//前一行皇后后移一列				
			}
			continue; //从新检测是否与前面所有皇后冲突
		}
		else { //无冲突，安排下一排皇后
			++i;
			if (i < sz) continue; 	//否则找到一个方案并输出		
			cout << "找到一个方案：";
			for (k = 0; k<sz; ++k) {
				cout << que[k];
			}
			cout << endl;
			break;
		}
	}
}

int main() {

	onesolution();

	return 0;
}