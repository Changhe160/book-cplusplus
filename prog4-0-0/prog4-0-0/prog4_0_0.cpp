#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	/*（此部分代码在书中4.1 引用 ）*/
	{
		int counter = 0;
		int &refCnt = counter; //refCnt引用counter对象的内容
							   //int &refCnt2; //错误：定义引用时必须和一个对象绑定
		refCnt = 2; // 修改了counter 所在的内存空间的内容
		int i = refCnt; //通过引用读取counter 对象的内容，并初始化对象i
						//	int i = 0;
		int &r1 = i, j = 0, &r2 = r1; // r1和r2都是i的引用，而j是int类型
									  //只能引用同类型的对象；
		double d = 0;//
					 //int &r3 = d; //错误：r3只能引用int类型对象
					 //引用的对象必须是非const左值（见2.5.1节，第21页）；
					 //	int i = 0; const int ci = 0;
					 //int &r4 = 100, &r5 = i + 1, &r6 = ci; //错误：只能引用非const左值
	}

	/*（此部分代码在书中4.1.1 引用const 对象）*/
	{
		const int ci = 0;
		const int &r1 = ci; //r1引用const 对象ci
							//r1 = 1; //错误：相当于修改const对象ci 的值
		int i = 0;
		//		const int &r1 = i; //正确：使用左值对象初始化
		const int &r2 = 1; //正确：使用字面值常量初始化
		const int &r3 = i + 1; //正确：使用表达式i+1 的结果初始化
		const int &r4 = 3.14; //正确：使用double类型数据初始化
	}
	/*（此部分代码在书中4.1.2 auto和引用）*/
	{
		int i = 0, &ri = i;
		auto r = ri; //r 是int类型而不是int 类型引用，auto被推导为int
					 //		auto &r = i; //r 是int类型引用
		const int ci = 0;
		auto &cr = ci; //cr 是const int类型引用，auto被推导为const int
	}
	/*（此部分代码在书中4.1.3 decltype和引用）*/
	{
		int i = 0, &r1 = i;
		decltype (r1) r2 = i; //r2为int引用
							  //decltype (r1 + 0) r2; //r2为int类型
		const int ci = 0;
		auto &cr = ci; //cr 是const int类型引用，auto被推导为const int
					   //decltype ((i)) r2; //错误：r2为int引用，必须初始化
	}
	/*（此部分代码在书中4.1.4 右值引用）*/
	{
		int i = 0;
		int &&rr1 = i + 1; //正确：rr1为右值引用，绑定到一个临时对象
						   //int &&rr2 = i; //错误：rr2为右值引用，不能绑定到左值对象
						   //int &&rr3 = rr1; //错误：rr1为左值，rr3不能绑定到左值对象
		int &&rr3 = std::move(rr1); //将rr1转换成右值
	}

	/*（此部分代码在书中4.1.4 右值引用 通用引用）*/
	{
		int i = 0;
		auto &&rr1 = 10; //rr1为右值引用
		auto &&rr2 = i; //rr2为左值引用
	}


	/*（此部分代码在书中4.2.1 指针的定义）*/
	{
		int i = 100;
		int *ptr = &i; //获取i的地址，并用其初始化指针对象ptr
		cout << *ptr << endl; //读操作，读取对象i的内容，输出100
		*ptr = 10; //写操作，修改对象i的内容，i的值变为10

		{
			int i = 0;
			int *ptr = &i; //*紧随int，故ptr为指针；&在表达式中，故为取址符
			int &ref = *ptr; //&紧随int，故ref为引用；*在表达式中，故为解引用
		}

		{
			int i = 10;
			//double *ptr = &i; //错误：ptr 和i的类型不匹配
		}
		{
			int i, *ptr1, *ptr2; //i为int类型，ptr1和ptr2为指针对象
		}
		{
			int *ptr1 = nullptr; //ptr1为空指针，没有指向任何对象
			int *ptr2; //ptr2为野指针，非常危
		}
		{
			int *p = 0; //p 为空指针
		}
	}
	/*（此部分代码在书中4.2.2 改变指向）*/
	{
		int i = 10, j = 100;
		int *ptr1 = &i, *ptr2 = &j; //ptr1指向i，ptr2指向j
		ptr1 = ptr2; //改变ptr1的指向，使其指向j，与ptr1 = &j;等价
		ptr1 = nullptr; //改变ptr1的指向，ptr1变成空指针
	}
	/*（此部分代码在书中4.2.3 const和指针）*/
	{
		const int ci = 10, cj = 1;
		const int *ptrc = &ci; //ptrc指向常量ci
							   //*ptrc = 0; //错误：不能修改ptrc指向的常量ci
		ptrc = &cj; //指向另外一个常量
		int i = 0;
		ptrc = &i; //还可以指向一个非const 对象
				   //int *ptr = &ci; //错误：ptr 不能指向常量
		{
			int j = 0, i = 0;
			int *const cptr = &i; //定义时初始化，cptr只能指向对象i
								  //cptr = &j; //错误：不能改变cptr的指向
			*cptr = 10; //正确：可以通过*cptr修改其指向的对象i的值
		}
		const int *const cptrc = &ci; //cptrc是一个指向常量ci 的常量指针
	}
	/*（此部分代码在书中4.2.4 类型推导和指针）*/
	{
		int i = 0;
		const int ci = 10;
		auto p = &i; //p被推导为int *类型
		auto pc = &ci; //pc被推导为const int * 类型，ci的const属性被保留
		auto &ref = i, *ptr = &i; //auto被推导为int
								  //auto &ref2 = i, ptr2 = &i; //错误：auto的推导类型不一致
		{
			int i = 0, *ptr = &i;
			decltype (ptr) ptr2; //ptr2为int *
			decltype (*ptr) refi = i; //正确：ref i为int &，必须初始化
			decltype (*ptr + 0) j; //正确：j为int类型
		}
	}
	/*（此部分代码在书中4.2.5 void指针）*/
	{
		double x = 0;
		int i = 0;
		void *p = &x; //正确：可以存放double类型对象的地址
		p = &i; //正确：也可以存放int 类型对象的地址
		{
			double x = 0, *ptrd = &x;
			void *ptr = &x;
			ptrd = static_cast<double *>(ptr); //需要强制类型转换
		}
	}
	/*（此部分代码在书中4.2.6 多级指针）*/
	{
		int i = 1, *ptr = &i;
		int **pptr = &ptr; //用指针对象ptr的地址初始化pptr
		cout << i << '\t' << *ptr << '\t' << **pptr << endl;
		int ***ppptr = &pptr;
		cout << ***ppptr << endl; //输出1
	}
	/*（此部分代码在书中4.2.7 引用和指针）*/
	{
		int i = 0, j = 1, &r = i, *p = &i;
		r = 4; //修改与r相绑定的对象i的值
		p = &j; //修改指针p的值，使其指向j
		{
			int i = 0;
			int *const p = &i; // 不允许指针p指向其他对象
			int &ri = i; //引用ri只能与i绑定
		}
	}
	/*（此部分代码在书中4.3.1 数组的定义和初始化）*/
	{
		int arr[10];
		unsigned cnt = 10;
		//int arr[cnt]; //错误，cnt不是常量表达式
		constexpr int sz = 10; //常量表达式（见2.4.2节，第18页）
		int arri[sz]; //正确：存放10个整型数据的数组
					  //float arrf[10.]; //错误：数组长度必须是整型
		{
			int arr[5] = { 1, 2, 3, 4, 5 };
		}
		{
			int arr[5] = { 1, 2, 3 }; //等价于arr[5] = {1, 2, 3, 0, 0}
		}
		{
			int arr[] = { 1, 2, 3, 4, 5 }; //数组arr的长度为5
		}
		{
			char name[] = "Lisha"; //自动添加字符串结束符’\0’
		}
		{
			char name[] = { 'L', 'i', 's', 'h', 'a', '\0' };
			//	name = "Lisha"; //错误：数组不允许赋值操作
		}
		{
			int arr[5]; //定义一个含有5个int类型元素的数组
			int *arrp[5]; //定义一个含有5个int*类型元素的数组，每个元素都是指针
			int(*parr)[5] = &arr; //定义一个指向含有5个int类型元素的数组的指针
			int(&rarr)[5] = arr; //定义arr的一个引用
								 //parrp 和rarrp 分别为指向指针数组arrp的指针和引用
			int *(*parrp)[5] = &arrp;
			int *(&rarrp)[5] = arrp;
		}
	}
	/*（此部分代码在书中4.3.2 访问数组元素）*/
	{
		int arr[5] = { 1, 2, 3, 4, 5 };
		arr[0] = 10; //写操作：修改第一个元素的值
		cout << arr[0] << endl; //读操作：读取第一个元素，输出结果为：10
		{
			int arr[5] = { 1,2,3,4,5 }; //定义并初始化一个含有5个整型数的数组
			for (auto i : arr) { //i为arr 中当前元素的副本
				cout << i << endl; //打印输出当前获取的整数
			}
			for (auto &i : arr) { //i 为arr中当前元素的引用
				i = 0; //写操作：每一个元素设置为0
			}
		}
	}
	/*（此部分代码在书中4.4.1 指针指向数组）*/
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr; //arr被转换成arr[0]的地址
		{
			int *p = &arr[0];
		}
		cout << arr << "," << &arr[0];//在我们的系统下，输出:010FF774,010FF774
		auto pa = arr; //pa 为int *类型，显然是一个指针
		cout << *pa; //输出arr[0]的值1
		decltype(arr) ar2; //ar2 为存放5个整型数的一维数组
		int a2d[3][5];
		int(*p2d)[5] = a2d; //指向a2d 的第一个元素
		{
			int(*p2d)[5] = &a2d[0]; //a2d 第一个元素的地址
		}
		{
			int *p2d[5];
		}
		{
			int * const p = &arr[0]; //arr可以理解为const 指针p
			cout << sizeof(arr) << " " << sizeof(p);
		}
	}
	/*（此部分代码在书中4.4.2 利用指针访问数组）*/
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr; //p指向数组arr
		int *p2 = p + 3; //返回p后面第3个元素的地址，即&arr[3]
		int *p3 = p++; //p后移一个位置，p3 指向p原来的位置&arr[0]
		int *p4 = ++p; //p 继续后移一个位置，p4 和p指向同一个位置&arr[2]
		p2 = &arr[0]; //正确：指向第一个元素，等价于p2 = arr;
		p2 = &arr[5]; //正确：指向尾元素后面的一个位置，等价于p2 = arr + 5;
		{
			int *p = arr; //p 指向数组arr
			int val = *(p + 2) + 1; //等价于int val = arr[2] + 1;
			int val2 = p[2]; //等价于int val2 = arr[2];
		}
		{
			int a2d[3][5];
			int(*p2d)[5] = a2d;
			p2d[1][1] = 1;
			*(*(p2d + 1) + 1) = 1; *(*(a2d + 1) + 1) = 1;
			*(p2d[1] + 1) = 1; *(a2d[1] + 1) = 1;
		}
		{
			int a2d[3][5] = { { 1 },{ 1 },{ 1 } };
			for (auto p = a2d; p < a2d + 3; ++p) {//p的类型为int (*)[5]
				for (auto q = *p; q < *p + 5; ++q) {//q的类型为int *
					cout << *q << " ";
				}
				cout << endl;
			}

			for (auto p = &a2d[0][0]; p < a2d[0] + 15; ++p) {
				if ((p - a2d[0]) % 5 == 0) //a2d[0]等价于&a2d[0][0]
					cout << endl; //每打印5个元素后换行
				cout << *p << " ";
			}
		}
	}
	/*（此部分代码在书中4.5.1 定义和初始化string对象）*/
	{
		string str1; //默认初始化，定义一个空字符串
		string str2(str1); //等价于string str2 = str1; str2是str1的一个拷贝
		string str3 = "Rosita"; //复制初始化
		string str4("Rosita");//直接初始化
		string str5(5, 'R'); //直接初始化，str5的内容为RRRRR
	}
	/*（此部分代码在书中4.5.2 string类型常用操作）*/
	{
		string s;
		cin >> s; //遇到空白字符停止
		cout << s; //输出s的内容
		getline(cin, s);
		{
			string s;
			cin >> s;
			cout << s.size() << endl;//输出s里面字符的个数，与s.length() 等价
			if (!s.empty()) //如果s 非空，则输出其内容
				cout << s;
		}
		string *ps = &s; //定义一个指针对象指向string对象s
		cout << ps->size() << endl; //通过指针调用size成员函数
		string s1 = "Hello C++";
		string s2 = "Hello";
		string s3 = "Hi";
		{
			string s1 = "Hello ", s2 = "C++";
			string s3 = s1 + s2;
			s1 += s2;
			string s4 = "Hello " + s2;
		}
		{
			string s = "hello";
			s[1] = 'H'; //对第二个元素进行写操作
			cout << s.at(1) << endl;
			cout << s.front() << " " << s.back() << endl; //打印输出h o
		}
	}
	/*（此部分代码在书中4.5.3 C风格字符串）*/
	{
		char cstr[] = "Hello";
		char *ps = cstr;//指向字符数组cstr
		char *ps2 = "C++";
		cout << ps << "," << ps2 << endl; //输出Hello,C++
		char cs[] = { 'C', '+ ', '+ ' };
		//cout << strlen(cs) << endl; //错误：cs没有以空字符结束
		char small[] = "C++", big[] = "Programming";
		//cout << strcpy(small, big) << endl; //错误：small 内存空间不足
		{
			string str = "hello";
			char carr[10];
			strcpy(carr, str.c_str());
		}
	}
	/*（此部分代码在书中4.6.1 定义和初始化vector 对象）*/
	{
		vector<int> v1; //存放整数的空vector
		vector<int> v2 = { 0,1,2 }; //v2有三个元素，值分别为0、1和2
		vector<int> v3(10); //v3可存放10个整数，值为默认值0
		vector<int> v4(10, 1); //v4存放10个整数1
		vector<string> v5 = { "Hi","Lisha","Mandy","Rosita" };
		vector<vector<int>> v6(10, v2);
	}
	/*（此部分代码在书中4.6.2 vector类型常用操作）*/
	{
		vector<int> vi;
		for (int i = 0; i < 100; ++i)
			vi.push_back(i);//依次添加100个数：0-99
		vi.pop_back();
		vi.clear();//或者移除所有元素：
	}
	/*（此部分代码在书中4.6.2 vector类型常用操作）*/
	{
		vector<int> vi = { 0,1,2,3 };
		auto itb = vi.begin();//itb指向vi的第一个元素
		auto ite = vi.end();//ite指向vi的尾后元素
		cout << *itb << endl; //输出第一个元素值0
		for (auto it = vi.begin(); it != vi.end(); ++it) {
			*it *= 2; //每个元素乘2
			cout << *it << endl;
		}
		vector<string> vs = { "Hi","Lisha","Mandy","Rosita" };
		for (auto it = vs.begin(); it != vs.end(); ++it) {
			cout << (*it).size() << endl;//选择string类成员函数size
		}
		//*it.size()；//错误：迭代器it没有成员函数size，相当于*(it.size());
		for (auto it = vs.begin(); it != vs.end(); ++it) {
			cout << it->size() << endl;
		}
	}
	/*（此部分代码在书中4.7 枚举类型）*/
	{
		{
			const int red = 0;
			const int green = 1;
			const int blue = 2;
		}
		{
			enum color { red, green, blue };
			//	enum emotion { happy, calm, blue };//错误：枚举成员blue已经定义过
			enum class stoplight { red, green, yellow };
			color c = red;//正确，可以访问color类型的枚举成员
						  //stoplight a = red; //错误：stoplight类型的枚举成员red在此不可访问
						  //或color类型的red与stoplight类型不匹配
			stoplight b = stoplight::red; //正确
			enum class week {
				Sunday = 7, Monday = 1, Tuesday, Wednesday,
				Thursday, Friday, Saturday
			};
			//color c1 = 1;//错误：类型不匹配
			color c2 = static_cast<color>(1);
			stoplight l = stoplight::red;
			switch (l) {
			case stoplight::red:
				cout << "stop!" << endl;
				break;
			case stoplight::green:
				cout << "pass carefully" << endl;
				break;
			case stoplight::yellow:
				cout << "slow down" << endl;
				break;
			default:
				cout << "light broken, call 122" << endl;
				break;
			}
		}
	}
	return 0;
}

