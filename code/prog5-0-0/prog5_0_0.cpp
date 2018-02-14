
#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
/*（此部分代码在书中5.1.1 定义函数 ）*/
int maximum(int a, int b) { //a和b为两个int 类型形参
	int c; //用来保存结果
	c = a > b ? a : b;
	return c;
}
/*（此部分代码在书中5.1.1 定义函数 ）*/
int fun() {
	int a = 0; //a为局部自动对象
	static int b = 0; //b为局部静态对象
	return ++b + ++a;
}
/*（此部分代码在书中5.2.3 全局对象 ）*/
int sum = 10; //定义全局对象
/*（此部分代码在书中5.2.3 全局对象 共享全局对象）*/
extern int g_val;
static int gs_val = 20; //gs_val内部链接性
/*（此部分代码在书中5.3 参数传递 ）*/
void Swap(int x, int y) {
	int z(x);
	x = y;
	y = z;
}//交换x和y的值
 /*（此部分代码在书中5.3.1 值传递 ）*/
void Swap(int *x, int *y) {//指针x和y分别指向实参i 和j
	int z(*x); //z 保存指针x指向的对象的值（实参i）
	*x = *y; //解引用不能省略
	*y = z;
} //交换x 和y所指向的对象的值
//  /*（此部分代码在书中5.3.2 引用传递 ）*/
//void Swap(int &x, int &y) {//x和y分别是实参i和j的别名
//	int z(x);
//	x = y;
//	y = z;
//} //交换x和y所绑定的对象的值
/*（此部分代码在书中5.3.3 const形参 ）*/
void f_cval(const int i); //i为const对象
void f_cptr(const int *i);//i指向const类型的实参
void f_cref(const int &i);//i为const类型实参的引用
void f_ref(int &i);//引用形参
/*（此部分代码在书中5.3.4 数组形参 ）*/
void fun(int *p) {}
//void fun(int p[]);//数组的方式
//void fun(int p[5]); //“指明”数组的长度
void print(char *str, unsigned size) {
	for (unsigned i = 0; i < size; ++i)
		cout << str[i];
}
void print(char *str) {
	if (str) //如果str不是一个空指针
		while (*str) //当前指针指向非空字符
			cout << *str++; //输出当前指针指向的字符并指向下一个字符
}
void print(char *beg, char * end) {
	//输出beg和end之间的元素（包含beg但不包含end指向的元素）
	while (beg != end)
		cout << *beg++; //输出当前指针指向的字符并指向下一个字符
}
void print(const char *str);
void print(const char *str, unsigned size);
void print(const char *beg, const char * end);
void fun(int(*a2d)[5]) {} //a2d指向一个含有5个元素的一维实参数组
//void fun(int a2d[][5]);
/*（此部分代码在书中5.4.1 无值返回 ）*/
//void Swap(int &x, int &y) {
//	if (x == y)
//		return;//显式返回主调函数
//	int z(x);
//	x = y;
//	y = z;
//	//隐式返回主调函数，无需return语句
//}
/*（此部分代码在书中5.4.2 有值返回 ）*/
//const int & maximum(const int &a, const int &b) {
//	return a > b ? a : b; //返回对象a或对象b的引用
//}
int & setMaximum(int &a, int &b) {
	return a > b ? a : b; //返回对象a 或对象b 的引用
}
//int * setMaximum(int &a, int &b) {
//	return a > b ? &a : &b; //返回引用a或b所绑定的实参对象的地址
//}
//int &maximum(int a, int b) {
//	return a > b ? a : b; //错误：返回局部对象a或b
//}
//int &maximum(int a, int b) {
//	static int c;
//	c = a > b ? a : b;
//	return c; //正确：返回静态局部对象c的引用
//}
/*（此部分代码在书中5.5.1 函数重载 ）*/
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const int& getMax(const int &a, const int &b, const int &c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}
/*（此部分代码在书中5.5.2 默认参数 ）*/
void turnoff(int time = 21) {}
//void turnoff(int time = getTime());
void print(int a, int b, int c = 3); //正确：部分参数具有默认值
//void print(int a, int b = 2, int c); //错误：最右侧参数没有默认值
//void print(int a = 1, int b = 2, int c = 3); //正确：所有参数具有默认值
void print(int a, int b = 2); //正确：声明时为形参b指定默认值
//void print(int a, int b = 2) { //错误：形参b的默认值已经指定
//	cout << a << "," << b << endl;
//}
/*（此部分代码在书中5.5.4 constexpr函数 ）*/
const int num = 30;
const int getNumber() { return 10; }
constexpr int f() { return 10; }
constexpr int getNumber(int i) { return i; }
/*（此部分代码在书中5.6.1 函数指针 ）*/
bool compareInt(int, int) { return true; } //比较两个整数大小
typedef bool(*pFun)(int, int);
//using pFun = bool(*)(int, int);
/*（此部分代码在书中5.8.1 宏定义调用函数 ）*/
#define PI 3.14159
void testPI(){
	cout << 2 * PI << endl;
}
#define fun2(a,b) (a)*(b)
#define fun3(a,b) a*b
void testFun() {
	cout << fun2(1 + 2, 3 - 2) << endl;
	cout << fun3(1 + 2, 3 - 2) << endl;
}
#define str(a) #a
#define glue(a,b) a##b
void testDefine(){
	cout << str(test) << endl;
	glue(c, out) << "test" << endl;
	int glue(x, 1) = 1;
#ifdef DEBUG
	cout << "x=" << x << endl;
#endif
#if 0
	cout << "此行代码永远也不会被编译" << endl;
#endif
}
int main() {
	/*（此部分代码在书中5.1.2 调用函数 ）*/
	{
		int x, y, z;
		cin >> x >> y;
		z = maximum(x, y); //调用函数maximum，x和y为实参
		cout << "The maximum value is " << z << endl;
	}
	/*（此部分代码在书中5.1.3 调用规则 ）*/
	{
		//maximum(1); //错误：实参数目不足
		//maximum("c++", "max"); //错误：类型不匹配
		//maxi(1, 2); //错误：函数名和被调函数名不一致
		//maximum(1, 2, 3); //错误：实参个数太多
		maximum(2.3, 4 + 1); //正确：第一个实参将被转换为int类型
	}
	/*（此部分代码在书中5.2.2 局部对象 ）*/
	{
		for (int i = 0; i < 3; ++i)
			cout << fun() << endl;
	}
	/*（此部分代码在书中5.2.3 全局对象 ）*/
	{
		int sum = 1; //定义局部对象
		std::cout << sum << std::endl; //访问局部对象sum，打印输出1
		std::cout << ::sum << std::endl; //访问全局对象sum，打印输出10
		cout << g_val + gs_val;
	}
	/*（此部分代码在书中5.3 参数传递 ）*/
	{
		int i(4), j(5);
		Swap(i, j);//调用Swap函数，实参i和j分别初始化Swap函数的形参x和y
		cout << "i=" << i << ",j=" << j << endl;//输出i=4,j=5
	}
	/*（此部分代码在书中5.3.1 值传递 ）*/
	{
		int i(4), j(5);
		Swap(&i, &j);//将实参i和j的地址传递给Swap函数
		cout << "i=" << i << ",j=" << j << endl;//输出i=5,j=4
	}
	/*（此部分代码在书中5.3.3 const形参 ）*/
	{
		const int cx = 1;
		int x = 1;
		//f_ref(41);//错误：左值引用不能绑定字面值常量
		//f_ref(cx);//错误：左值引用不能绑定常量
		//f_ref(x + 1);//错误：左值引用不能绑定右值表达式
	}
	/*（此部分代码在书中5.3.4 数组形参 ）*/
	{
		int arr[5] = { 1, 2 };
		fun(arr); //正确：数组名转化为首元素的地址
		fun(&arr[0]); //正确：显式传递首元素的地址
		{
			char arr[] = "Hello C++";
			print(arr);
		}
		{
			char arr[] = "Hello C++";
			print(begin(arr), end(arr));
		}
		{
			int matrix[4][5] = {};
			fun(matrix); //传递matrix首元素地址，即一个具有5个元素的一维数组
		}
	}
	/*（此部分代码在书中5.4.2 有值返回 ）*/
	{
		{
			int a = 10, b = 5;
			int c = maximum(a, b);
		}
		{
			//int x, y;
			//cin >> x >> y;
			//int z = maximum(x, y);
			//const int &ref = maximum(x, y);
		}
		{
			int x = 0, y = 1;
			setMaximum(x, y) = 10;
		}
		{
			//int x, y;
			//cin >> x >> y;
			//*setMaximum(x, y) = 10;
		}
	}
	/*（此部分代码在书中5.5.1 函数重载 ）*/
	{
		getMax(7, 8); //调用第一个重载函数
		getMax("C++", "Programming"); //调用第三个重载函数
	}
	/*（此部分代码在书中5.5.2 默认参数 ）*/
	{
		turnoff(); //省略实参，形参使用默认值，即21点关闭手机
		turnoff(22); //包含实参，形参接受实参值，即22点关闭手机
	}
	/*（此部分代码在书中5.5.4 constexpr函数 ）*/
	{
		const int numStudent = getNumber();
	//	int arr[numStudent];
		int stu1[getNumber(10)]; //正确：getNumber(10)是常量表达式
		int num = 10;
	//	int stu2[getNumber(num)]; //错误：运行时才能确定num的值
	}
	/*（此部分代码在书中5.6.1 函数指针 ）*/
	{
		bool(*pf)(int, int);
		//bool* pf(int, int);
		pFun pf1 = compareInt; //隐式初始化，pf1指向compareInt函数
		pFun pf2 = &compareInt; //显式初始化，pf2指向compareInt函数
		pFun pf3 = nullptr; //pf3不指向任何函数
		bool b1 = pf1(1, 2);
		bool b2 = (*pf2)(1, 2);
		//void(*a[5])(int);
		//void(*(*b)[5])(int);
		//void(*c(int, void(*fp)(int)))(int);
		using PF = void(*)(int);
		PF *a[5];
		PF(*b)[5];
		PF c(int, PF);
	}
	/*（此部分代码在书中5.6.2 lambda表达式 ）*/
	{
		{
			auto fun = [](int i) {cout << i << endl; };
			fun(17); //输出17
		}
		{
			int divisor = 5;
			vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
			for_each(numbers.begin(), numbers.end(), [divisor](int y) {
				if (y % divisor == 0) //divisor为外围divisor的拷贝
					cout << y << endl; //输出被divisor整除的元素
			});
			int sum = 0;
			for_each(numbers.begin(), numbers.end(), [divisor, &sum](int y) {
				if (y % divisor == 0) //sum为外围sum 的引用
					sum += y; //累加被divisor整除的元素，结果存放到外围对象sum中
			});
		}
	}
	testPI();
	testFun();
	testDefine();
	return 0;
}
