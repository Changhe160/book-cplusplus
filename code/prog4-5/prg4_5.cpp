/*
*找出扫雷小游戏中非雷方格周围所有无雷区域
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int fun() {
	int a = 0;
	static int b = 0;
	return ++a + ++b;
}
int main() {
	for (int i = 0; i < 3; ++i) cout << fun();
	srand(0);
	constexpr int sz = 8;
	char map[sz][sz];
	
	for (auto &row : map) 
		for (auto &col : row) 
			col = rand() % 100 < 50 ? '*' : '0';	
	ofstream out("map.txt");
	int i = 0;
	for (auto &row : map) {
		out << i / sz << "&";
		for (auto &col : row) {
			if (col == '*') out << "\\bomb";
			else out << i;
			i++;
			if (i % sz == 0) out << "\\\\\\cline{2-9}";
			else out << "&";
			
		}
		out << endl;
	}
	out.close();
		
	int cell;
	cout << "请输入选择的方格编号[0-" << sz*sz - 1 << "]:";
	cin >> cell;
	if (map[cell/sz][cell%sz] == '*') {
		cout << "选择的是地雷" << endl;
	}else {
		vector<int> result, nobomb(1,cell);
		map[cell / sz][cell%sz] = '1';
		do {
			cell = nobomb.front();
			int neibor[] = { (cell / sz < sz - 1) ? cell + sz : -1,(cell / sz > 0) ? cell - sz : -1,
				(cell % sz < sz - 1) ? cell + 1 : -1,cell % sz > 0 ? cell - 1 : -1 };
			for (auto &k : neibor) {
				if (k != -1 && map[k / sz][k%sz] == '0'){
					nobomb.push_back(k);
					map[k/sz][k%sz] = '1';
				}
			}
			result.push_back(nobomb.front());
			nobomb.erase(nobomb.begin());		
		} while (!nobomb.empty());
		for (auto i : result)
			cout << i << " ";
	}	
	return 0;
}