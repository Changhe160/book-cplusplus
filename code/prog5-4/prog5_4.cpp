/*
*�ݹ鷽�����˻ʺ�����
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isSafe(int i, const vector<int> &que) {
	for (int k = 0; k < i; ++k) {
		if (que[k] == que[i] || (abs(que[i] - que[k]) == abs(i - k)))
			return false;
	}
	return true;
}
void queen(int i, vector<int> &que, int&cnt) {
	if (i == 8) {
		cout << "����" << ++cnt << ":";
		for (int k = 0; k < que.size(); ++k)
			cout << que[k];
		cout << endl;
		return;
	}

	for (int k = 0; k < que.size(); ++k) {
		que[i] = k;
		if (isSafe(i, que)) { //�����ȫ��������һ�лʺ�
			queen(i + 1, que, cnt);
		}
	}
}
int main() {
	int sz = 8;
	vector<int> que(sz);
	int cnt = 0;
	queen(0, que, cnt);
}