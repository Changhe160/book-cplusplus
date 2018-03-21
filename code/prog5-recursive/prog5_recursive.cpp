#include<iostream>
using namespace std;

int sumTo(int i) {
	if (i == 0) 
		return 0;
	return 	sumTo(i - 1) + i;
}
void hanoi(int n, char src, char mid, char tar) {
	if (n == 1)
		cout << src << "-->" << tar << endl;
	else {
		hanoi(n - 1, src, tar, mid);
		cout << src << "-->" << tar << endl;
		hanoi(n - 1, mid, src, tar);
	}
}
int main() {
	/*int result;
	result = sumTo(3);
	cout << result << endl;*/
	int n;
	cin >> n;

	hanoi(3, 'A', 'B', 'C');

	return 0;
}
