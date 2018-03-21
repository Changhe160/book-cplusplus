
#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
/*���˲��ִ���������5.1.1 ���庯�� ��*/
int maximum(int a, int b) { //a��bΪ����int �����β�
	int c; //����������
	c = a > b ? a : b;
	return c;
}
/*���˲��ִ���������5.1.1 ���庯�� ��*/
int fun() {
	int a = 0; //aΪ�ֲ��Զ�����
	static int b = 0; //bΪ�ֲ���̬����
	return ++b + ++a;
}
/*���˲��ִ���������5.2.3 ȫ�ֶ��� ��*/
int sum = 10; //����ȫ�ֶ���
/*���˲��ִ���������5.2.3 ȫ�ֶ��� ����ȫ�ֶ���*/
extern int g_val;
static int gs_val = 20; //gs_val�ڲ�������
/*���˲��ִ���������5.3 �������� ��*/
void Swap(int x, int y) {
	int z(x);
	x = y;
	y = z;
}//����x��y��ֵ
 /*���˲��ִ���������5.3.1 ֵ���� ��*/
void Swap(int *x, int *y) {//ָ��x��y�ֱ�ָ��ʵ��i ��j
	int z(*x); //z ����ָ��xָ��Ķ����ֵ��ʵ��i��
	*x = *y; //�����ò���ʡ��
	*y = z;
} //����x ��y��ָ��Ķ����ֵ
//  /*���˲��ִ���������5.3.2 ���ô��� ��*/
//void Swap(int &x, int &y) {//x��y�ֱ���ʵ��i��j�ı���
//	int z(x);
//	x = y;
//	y = z;
//} //����x��y���󶨵Ķ����ֵ
/*���˲��ִ���������5.3.3 const�β� ��*/
void f_cval(const int i); //iΪconst����
void f_cptr(const int *i);//iָ��const���͵�ʵ��
void f_cref(const int &i);//iΪconst����ʵ�ε�����
void f_ref(int &i);//�����β�
/*���˲��ִ���������5.3.4 �����β� ��*/
void fun(int *p) {}
//void fun(int p[]);//����ķ�ʽ
//void fun(int p[5]); //��ָ��������ĳ���
void print(char *str, unsigned size) {
	for (unsigned i = 0; i < size; ++i)
		cout << str[i];
}
void print(char *str) {
	if (str) //���str����һ����ָ��
		while (*str) //��ǰָ��ָ��ǿ��ַ�
			cout << *str++; //�����ǰָ��ָ����ַ���ָ����һ���ַ�
}
void print(char *beg, char * end) {
	//���beg��end֮���Ԫ�أ�����beg��������endָ���Ԫ�أ�
	while (beg != end)
		cout << *beg++; //�����ǰָ��ָ����ַ���ָ����һ���ַ�
}
void print(const char *str);
void print(const char *str, unsigned size);
void print(const char *beg, const char * end);
void fun(int(*a2d)[5]) {} //a2dָ��һ������5��Ԫ�ص�һάʵ������
//void fun(int a2d[][5]);
/*���˲��ִ���������5.4.1 ��ֵ���� ��*/
//void Swap(int &x, int &y) {
//	if (x == y)
//		return;//��ʽ������������
//	int z(x);
//	x = y;
//	y = z;
//	//��ʽ������������������return���
//}
/*���˲��ִ���������5.4.2 ��ֵ���� ��*/
//const int & maximum(const int &a, const int &b) {
//	return a > b ? a : b; //���ض���a�����b������
//}
int & setMaximum(int &a, int &b) {
	return a > b ? a : b; //���ض���a �����b ������
}
//int * setMaximum(int &a, int &b) {
//	return a > b ? &a : &b; //��������a��b���󶨵�ʵ�ζ���ĵ�ַ
//}
//int &maximum(int a, int b) {
//	return a > b ? a : b; //���󣺷��ؾֲ�����a��b
//}
//int &maximum(int a, int b) {
//	static int c;
//	c = a > b ? a : b;
//	return c; //��ȷ�����ؾ�̬�ֲ�����c������
//}
/*���˲��ִ���������5.5.1 �������� ��*/
const int& getMax(const int &a, const int &b) {
	return a > b ? a : b;
}
const int& getMax(const int &a, const int &b, const int &c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
const string& getMax(const string &a, const string &b) {
	return a > b ? a : b;
}
/*���˲��ִ���������5.5.2 Ĭ�ϲ��� ��*/
void turnoff(int time = 21) {}
//void turnoff(int time = getTime());
void print(int a, int b, int c = 3); //��ȷ�����ֲ�������Ĭ��ֵ
//void print(int a, int b = 2, int c); //�������Ҳ����û��Ĭ��ֵ
//void print(int a = 1, int b = 2, int c = 3); //��ȷ�����в�������Ĭ��ֵ
void print(int a, int b = 2); //��ȷ������ʱΪ�β�bָ��Ĭ��ֵ
//void print(int a, int b = 2) { //�����β�b��Ĭ��ֵ�Ѿ�ָ��
//	cout << a << "," << b << endl;
//}
/*���˲��ִ���������5.5.4 constexpr���� ��*/
const int num = 30;
const int getNumber() { return 10; }
constexpr int f() { return 10; }
constexpr int getNumber(int i) { return i; }
/*���˲��ִ���������5.6.1 ����ָ�� ��*/
bool compareInt(int, int) { return true; } //�Ƚ�����������С
typedef bool(*pFun)(int, int);
//using pFun = bool(*)(int, int);
/*���˲��ִ���������5.8.1 �궨����ú��� ��*/
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
	cout << "���д�����ԶҲ���ᱻ����" << endl;
#endif
}
int main() {
	/*���˲��ִ���������5.1.2 ���ú��� ��*/
	{
		int x, y, z;
		cin >> x >> y;
		z = maximum(x, y); //���ú���maximum��x��yΪʵ��
		cout << "The maximum value is " << z << endl;
	}
	/*���˲��ִ���������5.1.3 ���ù��� ��*/
	{
		//maximum(1); //����ʵ����Ŀ����
		//maximum("c++", "max"); //�������Ͳ�ƥ��
		//maxi(1, 2); //���󣺺������ͱ�����������һ��
		//maximum(1, 2, 3); //����ʵ�θ���̫��
		maximum(2.3, 4 + 1); //��ȷ����һ��ʵ�ν���ת��Ϊint����
	}
	/*���˲��ִ���������5.2.2 �ֲ����� ��*/
	{
		for (int i = 0; i < 3; ++i)
			cout << fun() << endl;
	}
	/*���˲��ִ���������5.2.3 ȫ�ֶ��� ��*/
	{
		int sum = 1; //����ֲ�����
		std::cout << sum << std::endl; //���ʾֲ�����sum����ӡ���1
		std::cout << ::sum << std::endl; //����ȫ�ֶ���sum����ӡ���10
		cout << g_val + gs_val;
	}
	/*���˲��ִ���������5.3 �������� ��*/
	{
		int i(4), j(5);
		Swap(i, j);//����Swap������ʵ��i��j�ֱ��ʼ��Swap�������β�x��y
		cout << "i=" << i << ",j=" << j << endl;//���i=4,j=5
	}
	/*���˲��ִ���������5.3.1 ֵ���� ��*/
	{
		int i(4), j(5);
		Swap(&i, &j);//��ʵ��i��j�ĵ�ַ���ݸ�Swap����
		cout << "i=" << i << ",j=" << j << endl;//���i=5,j=4
	}
	/*���˲��ִ���������5.3.3 const�β� ��*/
	{
		const int cx = 1;
		int x = 1;
		//f_ref(41);//������ֵ���ò��ܰ�����ֵ����
		//f_ref(cx);//������ֵ���ò��ܰ󶨳���
		//f_ref(x + 1);//������ֵ���ò��ܰ���ֵ���ʽ
	}
	/*���˲��ִ���������5.3.4 �����β� ��*/
	{
		int arr[5] = { 1, 2 };
		fun(arr); //��ȷ��������ת��Ϊ��Ԫ�صĵ�ַ
		fun(&arr[0]); //��ȷ����ʽ������Ԫ�صĵ�ַ
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
			fun(matrix); //����matrix��Ԫ�ص�ַ����һ������5��Ԫ�ص�һά����
		}
	}
	/*���˲��ִ���������5.4.2 ��ֵ���� ��*/
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
	/*���˲��ִ���������5.5.1 �������� ��*/
	{
		getMax(7, 8); //���õ�һ�����غ���
		getMax("C++", "Programming"); //���õ��������غ���
	}
	/*���˲��ִ���������5.5.2 Ĭ�ϲ��� ��*/
	{
		turnoff(); //ʡ��ʵ�Σ��β�ʹ��Ĭ��ֵ����21��ر��ֻ�
		turnoff(22); //����ʵ�Σ��βν���ʵ��ֵ����22��ر��ֻ�
	}
	/*���˲��ִ���������5.5.4 constexpr���� ��*/
	{
		const int numStudent = getNumber();
	//	int arr[numStudent];
		int stu1[getNumber(10)]; //��ȷ��getNumber(10)�ǳ������ʽ
		int num = 10;
	//	int stu2[getNumber(num)]; //��������ʱ����ȷ��num��ֵ
	}
	/*���˲��ִ���������5.6.1 ����ָ�� ��*/
	{
		bool(*pf)(int, int);
		//bool* pf(int, int);
		pFun pf1 = compareInt; //��ʽ��ʼ����pf1ָ��compareInt����
		pFun pf2 = &compareInt; //��ʽ��ʼ����pf2ָ��compareInt����
		pFun pf3 = nullptr; //pf3��ָ���κκ���
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
	/*���˲��ִ���������5.6.2 lambda���ʽ ��*/
	{
		{
			auto fun = [](int i) {cout << i << endl; };
			fun(17); //���17
		}
		{
			int divisor = 5;
			vector<int> numbers{ 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
			for_each(numbers.begin(), numbers.end(), [divisor](int y) {
				if (y % divisor == 0) //divisorΪ��Χdivisor�Ŀ���
					cout << y << endl; //�����divisor������Ԫ��
			});
			int sum = 0;
			for_each(numbers.begin(), numbers.end(), [divisor, &sum](int y) {
				if (y % divisor == 0) //sumΪ��Χsum ������
					sum += y; //�ۼӱ�divisor������Ԫ�أ������ŵ���Χ����sum��
			});
		}
	}
	testPI();
	testFun();
	testDefine();
	return 0;
}
