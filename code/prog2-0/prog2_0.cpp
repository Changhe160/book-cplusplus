#include <iostream>
using namespace std;

/* 代码清单1.3,第6页 */
class Cylinder { 
	double m_radius, m_height;
public:
	double volume() {//定义了一个与半径和高关联的操作，即求体积并返回体积値
		return 3.14*m_radius*m_radius*m_height;
	}
	Cylinder(double i = 0, double h = 0) :m_radius(i), m_height(h) {}

};
//2.3.2节
//extern int i = 0; //定义i
//int i = 5; //错误：对象i已经定义过

constexpr int getNumber()
{
	return 0;
}

int main()
{
	{//2.2.2节
		cout << "Hi \"\103++\"\n"; // 输出Hi "C++"，转到新一行 （此行代码在书中p13）
	}
	
	{//2.3.1节
		int counter,age; // 定义两个整型类型对象counter和age
		Cylinder object; // 定义一个Cylinder类（见例1.3，第6页）类型对象object
	}

	{//2.3.1节
		int age = 18;
	}
	{//2.3.1节
		int year = 2017, birthYear = year;//year先于birthYear创建和初始化，可用于初始化birthYear
	}

	{//2.3.1节
		int year = 0; //定义对象并初始化，在此之前， year在内存中不存在
		year = 2017; //赋值操作，在对year赋值之前，其在内存中已经存在
	}

	{//2.3.1节
		int year(2017); //直接初始化
	}

	{//2.3.1节
		int year{ 2017 }; //列表初始化，C++11

	}

	{//2.3.1节
		int year = { 2017 }; //列表初始化，C++11

	}

	{//2.3.1节
		int year{}; //可以不提供初始值，默认为0，C++11
	}

	{//2.3.2节
		extern int i; //在另外一个文件里面声明对象i，而非定义i，i已经定义过了
		int j; //可以理解为声明并定义j
	}
	
	{//2.4.1节
		const double pi = 3.14159; //圆周率
		const int numStudent = 30; //一个班级的学生人数
		int i = 100;
		const int ci = i; //利用对象i 的值初始化ci
		//numStudent = 50; //错误：不能对numStudent进行写值操作
		//ci = 50; //错误：不能对const对象ci进行写值操作
		//const double pi; //错误：const对象必须初始化
	}

	{//2.4.2节
		int num = 100;
		const int numStudent = num; //numStudent虽是一个const对象，但其值只有在程序运行期间获取，编译期间不能获取
	}

	{//2.4.2节
		constexpr int number = 10; // 10 是常量表达式
		constexpr int maxNumber = number + 1; //number+1是常量表达式
		constexpr int num = getNumber(); //是否合法取决于函数getNumber的属性
	}

	{//2.4.3节
		typedef double price; // price是double的一个类型别名
		price car = 1E5, mobile = 100.; //car和mobile存放的都是价格
	}

	{//2.4.3节
		using price = double; //用using声明double的以个别名price
		price car = 1E5, mobile = 100.; //car和mobile存放的都是价格
	}

	{//2.4.3节
		auto pi = 3.14159, rad = 1.0; // pi 和rad都为double类型
		auto area = pi * rad * rad; // area为double类型
	}

	{//2.4.3节
		//auto i = 0, pi = 3.14159; // 错误：i和pi的类型不一致
	}

	{//2.4.3节
		const double pi = 3.14159;
		auto rad = pi; //rad是一个double类型数，pi的const属性被忽略
	}

	{//2.4.3节
		const double pi = 3.14159;
		const auto rad = pi; //rad是const double类型;
	}

	{//2.4.3节
		int i = 0;
		decltype (i) j = 1; //j为int类型
		decltype (i + j) k = 0; //k为int类型
	}

	{//2.4.3节
		const double pi = 3.14159;
		decltype (pi) rad = 1.0; //rad为const double类型
	}

	{//2.5.1节
		int i = 0; //正确：用右值常量0 初始化左值对象i
		//10 = i; //错误，赋值运算符左侧必须为左值
		int j = i; // 左值对象i 可以当成右值，只对其内容进行读操作
		const int N = 100; // N为右值对象
		//N = 40; // 错误：不能改变右值对象N的值
	}

	{//2.5.2节
		21 / 6; //结果是3，余数被舍弃
		21 % -4; //结果为1
		-21 % 4; //结果为-1
	}

	{//2.5.2节
		//32 / 0; // 除数为0
		short val = 32767; //short类型占2个字节，其表示的最大值为32767
		val += 1; //val本身加1，结果超出其表示范围，出现数据溢出
		std::cout << val;
	}

	{//2.5.3节
		int i = 0, j = i; //初始化而非赋值
		i = 0; //赋值而非初始化
		//i + j = 10; //错误：算术表达式为右值
	}

	{//2.5.3节
		int i = 0, j=0;
		double d = 3.14159;
		i = d; //表达式的结果的类型是int，值是3
		//i = { 3.14159 }; //错误：窄化转换
		i = 0, j = 0;
		i = j = 5; //i 和j 的值都是5 另外，赋值运算符的优先级是比较低的，所以我们
		//i = 2 + j = 4; //错误：2 + j 为右值，不能作为第二个赋值符号的左侧对象
		i = 2 + (j = 4); //正确：把j = 4的值加上2赋给i ，i和j 的值分别为6和4
	}

	{//2.5.3节
		int counter=0,i=1,j=1;
		counter += 1; //等效于counter = counter + 1;
		i *= j + 3; //等效于i =i * (j + 3);
	}

	{//2.5.4节
		int i = 0, j;
		j = i++;//后置，i的值自增变为1，表达式i++ 的值为i自增之前的值，即j 的值为0
		j = ++i;//前置，i的值自增变为2，表达式++i 的值为i 自增之后的值，即j 的值为2
	}

	{//2.5.5节
		int i = 1, j = 2;
		bool b = !i && ++j; // b的值是0，j的值是2
	}

	{//2.5.6节
		int i, j;
		i = (j = 3, j += 6, 5 + 6); // i的值为11, j的值为9
	}

	{//2.5.7节
		int a = 4, b = 5, c = 6, max;
		max = a > b ? (a > c ? a : c) : (b > c ? b : c);
	}

	{//2.5.8节
		cout << sizeof(int); //输出4
		int i = 0;
		cout << sizeof(++i);//输出4，i的值为0
	}

	{//2.5.9节
		short a = 3, b = 5;
	}

	{//2.5.10节
		int i = 0, j;
		j = i * 2 + i++;
	}

	{//2.6.2节
		int i = 5, j = 3;
		double k = i / static_cast<double>(j); //强制将j转化为double 类型
	}

	{//2.6.2节
		double i = 5., j = 3.;
		int k = static_cast<int>(i / j);//强制将i / j的结果转化为int
	}

	{//2.6.2节
		int i = 5,j=3;
		double k = i / (double)j; //强制将j 转化为double类型
	}

	{//2.6.2节
		int i = 5,j=3;
		double k = i / double(j);
	}
}
