// Calculator based on stack

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Calculator {
private:
	stack<double> m_num; // 数字栈
	stack<string> m_opr; // 运算符栈
	static vector<string> m_oprLib; // 运算符库

	// 知识, 得到运算符优先级
	int getPrecedence(const string &s, bool isCurrent) const;

	// 读取运算符
	string readOpr(string::const_iterator &it);

	// 读取操作数
	double readNum(string::const_iterator &it);

	// 动作, 使用运算符栈和操作数栈顶的元素进行计算并修改两个栈
	void calculate();

	// 知识, 判断字符是否为数字
	// 改写, 加上对'-'是负号还是减号进行判断的功能
	// 注意判断迭代器越界(unfinished)
	bool isNum(string::const_iterator &c) const
	{
		if (*c >= '0'&&*c <= '9' || *c == '.')
		{ 
			return true;
		}
		else
		{
			return false;
		}
	}

	// 对字符串进行分割并调用其他函数进行工作
	void process(const string &str);

public:
	// 无参构造函数
	Calculator();
	
	double doIt(const string &eqt);
};



