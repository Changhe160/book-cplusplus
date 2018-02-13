#include <iostream>
using namespace std;
int main() {
	constexpr int sz = 8;
	int que[sz] = { 0 };//每一行皇后都从第0列开始摆放
	int i = 0;//从第0行开始摆放
	while (i >= 0) {
		int k = 0;
		while (k<i) {//检查前面所有皇后是否和第i行皇后冲突
			if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k)))
				++k;//第k行和第i行皇后没有冲突
			else
				break;//第k行和第i行皇后产生冲突，退出，转到第15行
		}
		if (k < i) {//检测到冲突
			++que[i];//处理冲突：移动第i行皇后到当前位置的下一列
			while (que[i] == sz) {//当前行所有尝试都失败，需要回溯
				que[i] = 0; //重置当前行皇后位置
				--i;//回溯到上一行
				if (i < 0)
					break; //如果回溯到第0行之前，结束运行，转到第24行
				++que[i];//前一行皇后后移一列
			}
			continue; //从新检测是否与前面已安排皇后冲突，转到第7行
		}
		else { //没有检测到冲突，安排下一行皇后
			++i;//移动到下一行
			if (i < sz)
				continue; //安排下一行皇后，已安排在第0列，转到第7行
			cout << "找到一个方案：";//否则找到一个方案并输出
			for (k = 0; k<sz; ++k)
				cout << que[k];
			cout << endl;
			break; //结束运行，转到第37行
		}
	}
	return 0;
}