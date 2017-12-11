#include"List.h"

int main() {
	SList<int> l;
	int val;
	while (cin >> val) {
		l.push_back(val);
	}
	cout << l << endl;



	Node<int> *pos = l.find(20);

	l.insert(pos, 25);
	cout << l << endl;
	
	l.erase(25);
	cout << l << endl;
	return 0;
}