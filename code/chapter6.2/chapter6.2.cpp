#include "Fraction.h"

class Foo {
	int &m_ref;
	const int m_con;
public:
	Foo(int &i) :m_ref(i), m_con(i) {
	
	}
};
class Employee {
	int m_id;
	string m_name;
public:
	Employee(int id = 0, const string &name = "") :m_id(id), m_name(name) {
	
	}

	Employee(const string &name) :Employee(0, name) {//委托构造函数
	
	}

	Employee(const Employee &) = delete;

};

int main() {
	//6.2.1
	{
		Fraction a;			//默认构造函数
		Fraction b(1, 5);	//直接初始化
		int i;
		Foo f(i);
		
		Employee member("Kevin"); 
	}
	//6.2.2
	{
		Fraction a(1, 5);	//直接初始化
		Fraction b(a);		//直接初始化，b为对象a的拷贝
		Fraction c = Fraction(3, 2); //复制初始化
		Fraction d = 7;		//复制初始化

		//Fraction d2 = static_cast<Fraction>(7); //当我们将 Fraction 类的默认构造函数声明为 explicit 之后

		Fraction e = divide(b, c);

		Employee e1;
		//Employee e2(e1);//错误：不能调用删除的复制构造函数
	}
}