#include <iostream>
using namespace std;

int main()
{
	{//3.1.1节
		int counter=0;
		counter + 1; //一条没有实际意义的表达式语句
		counter += 1; //一条有用的复合赋值语句
		; //空语句
		counter += 1;; //第二个分号不会影响该语句的执行
	}

	{//3.1.1节
		int counter = 0;
		//while (counter < 10); //一个多余的分号导致程序死循环
		++counter;
	}

	{//3.1.2节
		{ //语句块开始
			int sum = 0; // 定义一个对象
		    /*...*/
		} //语句块结束
	}

	{//3.1.3节
		int counter = 0, sum= 0;
		while (counter < 10) { //while作用域从这里开始
			++counter;
			sum += counter;
		} //while作用域到这里结束
	}

	{//3.2.1节
		if (int i = 10) {
			/*...*/
		}
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) //n被2整除
			if (n % 3 == 0) //n被3整除
				cout << "n是6的倍数";
			else //n被2整除但不能被3整除
				cout << "n是2的倍数不是3的倍数";
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0)
				cout << "n是6的倍数";
		}
		else //n不能被2整除
			cout << "n不是2的倍数";
	}

	{//3.2.1节
		int n;
		cout << "请输入一个整数： " << endl;
		cin >> n;
		if (n % 2 == 0) {
			if (n % 3 == 0) {
				cout << "n是6的倍数";
			}
		}
		else {
			cout << "n不是2的倍数";
		}
	}

	{//3.3.3节
		int sum = 0;
		for (int i = 1; i <= 100; ++i) {
			sum += i; //1到i的累加和放到sum中
		}
	}

	{//3.3.3节
		int sum = 0;
		for (int i = 1, j = 100; i < j; ++i, --j) {
			sum += i + j;
		}
	}

	{//3.4.2节
		for (int i = 0; i < 5; ++i) {//当i为奇数，输出*#，为偶数时无输出
			if (i % 2) {
				cout << "*";//打印符号*，然后再打印符号#
			}
			else {
				continue;//结束当前迭代，跳转到for语句，执行++i
			}
			cout << "#";
		}
	}
}