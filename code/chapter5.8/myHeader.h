
//5.8.3 头文件
#ifndef MYHEADER_H
#define MYHEADER_H
const double pi = 3.1415926;	//const对象
int add(int, int);				//函数声明
extern int g_sum;				//全局对象声明

inline bool isNumber(char ch) {     //内联函数
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
constexpr int scale() {				//constexpr 函数
	return 10;
}

class myClass {  };					//类定义

template<typename T>				//函数模板
const T& getMax(const T &a, const T &b) {
	return a > b ? a : b;
}
#endif // !MYHEADER_H

