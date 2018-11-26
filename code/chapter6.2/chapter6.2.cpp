#include "Fraction.h"

int main() {

	//6.2.2
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		Fraction c = Fraction(3, 2); //复制初始化
		Fraction d = 7;		//复制初始化
		Fraction d2 = 7;	//错误：无法将 int 类型转换为 Fraction 类型（当我们将 Fraction 类的默认构造函数声明为 explicit 之后）
	}
}