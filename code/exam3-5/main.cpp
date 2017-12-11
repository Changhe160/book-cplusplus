/*
*迭代法求pi的近似值
*/
#include<iostream>
#include <iomanip> 
using namespace std;

int main() {
	double sum=0,x=1;
	int i = 1;
	while (x > 1.0E-10) {
		sum += x;
		++i;
		x *= (i - 1.) / (2 * i - 1);
	}
	cout << "pi=" << fixed << setprecision(10) << 2 * sum << endl;

	return 0;
}