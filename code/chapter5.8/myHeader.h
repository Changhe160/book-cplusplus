
//5.8.3 ͷ�ļ�
#ifndef MYHEADER_H
#define MYHEADER_H
const double pi = 3.1415926;	//const����
int add(int, int);				//��������
extern int g_sum;				//ȫ�ֶ�������

inline bool isNumber(char ch) {     //��������
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
constexpr int scale() {				//constexpr ����
	return 10;
}

class myClass {  };					//�ඨ��

template<typename T>				//����ģ��
const T& getMax(const T &a, const T &b) {
	return a > b ? a : b;
}
#endif // !MYHEADER_H

