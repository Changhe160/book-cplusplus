/*
*����30��ѧ����ѧ��Ŀƽ���ɼ��ͱ�׼��
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	int a2d[][2] = { 1,1,4 ,4,4};
	srand(0);
	constexpr int sz = 30;
	int score[sz];
	int mean = 0;
	for (auto &i:score) {
		i = 50+rand() % 50;
		mean += i;
	}
	mean /= sz;
	double dev = 0;
	for (int i = 0; i < sz; ++i) {
		dev+=pow(score[i]- mean,2);
	}
	dev = sqrt(dev / sz);
	cout << "ƽ���ɼ���" << mean <<" ��׼�"<<dev<< endl;
	return 0;
}