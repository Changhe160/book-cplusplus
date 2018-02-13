/*
*找出扫雷小游戏中非雷方格周围所有无雷区域
*/#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip> //使用库函数setw
using namespace std;
int main() {
	srand(0);
	constexpr int sz = 8;
	char map[sz][sz];
	for (auto &row : map)
		for (auto &col : row)//以0.5的概率设置地雷，使用条件表达式简化代码
			col = rand() % 100 < 50 ? '*' : '0';
	//打印地图，函数setw设置打印字符的宽度（见10.2.2节，第219页）
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (map[i][j] == '*') cout << setw(3) << "*";
			else cout << setw(3) << i*sz + j;
		}
		cout << endl;
	}
	int cell;
	cout << "请输入选择的方格编号[0-" << sz*sz - 1 << "]:";
	cin >> cell;
	if (map[cell / sz][cell%sz] == '*') {
		cout << "选择的是地雷" << endl;
	}
	else {//容器nobomb存放未处理的方格编号，初始值为选择的方格编号
		vector<int> result, nobomb(1, cell);
		map[cell / sz][cell%sz] = '1';//标记该方格已经遍历
		do {//取出nobomb中第一个待处理的方格编号，找到与cell相邻的方格
			cell = nobomb.front();
			//neibor存放与cell相邻的4个方格编号，如果没有对应方格编号标记为-1
			int neibor[] = { (cell / sz<sz - 1) ? cell + sz : -1,(cell / sz>0) ? cell - sz : -1,
				(cell%sz<sz - 1) ? cell + 1 : -1,(cell%sz>0) ? cell - 1 : -1 };
			for (auto &k : neibor) {//注意k!=-1必须放到逻辑与的左侧
				if (k != -1 && map[k / sz][k%sz] == '0') {
					nobomb.push_back(k);//所有与cell相邻的无雷方格放到nobomb中
					map[k / sz][k%sz] = '1';//标记该方格已经遍历过
				}
			}
			result.push_back(cell); //将处理完的方格编号cell放到result中
			nobomb.erase(nobomb.begin()); //将cell从nobomb中移除
		} while (!nobomb.empty());
		for (auto i : result)
			cout << i << " ";
	}
	return 0;
}
