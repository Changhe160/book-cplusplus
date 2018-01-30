#include <iostream>
using namespace std;

inline void swap(int & x, int &y) {
	int z(x);
	x = y;
	y = z;
}
inline void swap(int * x, int *y) {
	int *z(x);
	x = y;
	y = z;
}
int main() {
	int a(0), b(1);
	swap(&a, &b);
	cout << a << " " << b<<endl;
	system("pause");
}