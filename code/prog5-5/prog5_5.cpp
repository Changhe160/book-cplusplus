#include<iostream>
using namespace std;

void hanoi(int n, char src, char mid, char tar) {
	if (n == 1)
		cout << src << "-->" << tar << '\t';
	else {
		hanoi(n - 1, src, tar, mid); 
		cout << src << "-->" << tar << '\t';
		hanoi(n - 1, mid, src, tar);
	}
}
int main() {
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
