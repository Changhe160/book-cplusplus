#include "myHeader.h"
#include <iostream>

using namespace std;
int main() {
	g_sum = add(4, 5);
	cout << g_sum << endl;
	enum class stoplight
	{red, green,yellow

	};

	stoplight l = stoplight::red;
	switch (l){
	case stoplight::red:
		cout << "stop!" << endl;
		break;
	case stoplight::green:
		cout << "pass carefully" << endl;
		break;
	case stoplight::yellow:
		cout << "slow down" << endl;
		break;
	default:
		cout << "light broken, call 110" << endl;
		break;
	}
}