#include<iostream>
using namespace std;

void hanoi(int n, char src, char mid, char tar) {
	if (n == 1)
		cout << src << "-->" << tar << '\t';
	else {
		hanoi(n - 1, src, tar, mid);//将n-1个盘子移到中间柱上
	    cout << src << "-->" << tar << '\t';//将最后一个盘子移到目标柱上
		hanoi(n - 1, mid, src, tar);//将n-1个盘子从中间柱移到目标柱上
	}
}
int main() {
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
