#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	/*���˲��ִ���������4.1 ���� ��*/
	{
		int counter = 0;
		int &refCnt = counter; //refCnt����counter���������
							   //int &refCnt2; //���󣺶�������ʱ�����һ�������
		refCnt = 2; // �޸���counter ���ڵ��ڴ�ռ������
		int i = refCnt; //ͨ�����ö�ȡcounter ��������ݣ�����ʼ������i
						//	int i = 0;
		int &r1 = i, j = 0, &r2 = r1; // r1��r2����i�����ã���j��int����
									  //ֻ������ͬ���͵Ķ���
		double d = 0;//
					 //int &r3 = d; //����r3ֻ������int���Ͷ���
					 //���õĶ�������Ƿ�const��ֵ����2.5.1�ڣ���21ҳ����
					 //	int i = 0; const int ci = 0;
					 //int &r4 = 100, &r5 = i + 1, &r6 = ci; //����ֻ�����÷�const��ֵ
	}

	/*���˲��ִ���������4.1.1 ����const ����*/
	{
		const int ci = 0;
		const int &r1 = ci; //r1����const ����ci
							//r1 = 1; //�����൱���޸�const����ci ��ֵ
		int i = 0;
		//		const int &r1 = i; //��ȷ��ʹ����ֵ�����ʼ��
		const int &r2 = 1; //��ȷ��ʹ������ֵ������ʼ��
		const int &r3 = i + 1; //��ȷ��ʹ�ñ��ʽi+1 �Ľ����ʼ��
		const int &r4 = 3.14; //��ȷ��ʹ��double�������ݳ�ʼ��
	}
	/*���˲��ִ���������4.1.2 auto�����ã�*/
	{
		int i = 0, &ri = i;
		auto r = ri; //r ��int���Ͷ�����int �������ã�auto���Ƶ�Ϊint
					 //		auto &r = i; //r ��int��������
		const int ci = 0;
		auto &cr = ci; //cr ��const int�������ã�auto���Ƶ�Ϊconst int
	}
	/*���˲��ִ���������4.1.3 decltype�����ã�*/
	{
		int i = 0, &r1 = i;
		decltype (r1) r2 = i; //r2Ϊint����
							  //decltype (r1 + 0) r2; //r2Ϊint����
		const int ci = 0;
		auto &cr = ci; //cr ��const int�������ã�auto���Ƶ�Ϊconst int
					   //decltype ((i)) r2; //����r2Ϊint���ã������ʼ��
	}
	/*���˲��ִ���������4.1.4 ��ֵ���ã�*/
	{
		int i = 0;
		int &&rr1 = i + 1; //��ȷ��rr1Ϊ��ֵ���ã��󶨵�һ����ʱ����
						   //int &&rr2 = i; //����rr2Ϊ��ֵ���ã����ܰ󶨵���ֵ����
						   //int &&rr3 = rr1; //����rr1Ϊ��ֵ��rr3���ܰ󶨵���ֵ����
		int &&rr3 = std::move(rr1); //��rr1ת������ֵ
	}

	/*���˲��ִ���������4.1.4 ��ֵ���� ͨ�����ã�*/
	{
		int i = 0;
		auto &&rr1 = 10; //rr1Ϊ��ֵ����
		auto &&rr2 = i; //rr2Ϊ��ֵ����
	}


	/*���˲��ִ���������4.2.1 ָ��Ķ��壩*/
	{
		int i = 100;
		int *ptr = &i; //��ȡi�ĵ�ַ���������ʼ��ָ�����ptr
		cout << *ptr << endl; //����������ȡ����i�����ݣ����100
		*ptr = 10; //д�������޸Ķ���i�����ݣ�i��ֵ��Ϊ10

		{
			int i = 0;
			int *ptr = &i; //*����int����ptrΪָ�룻&�ڱ��ʽ�У���Ϊȡַ��
			int &ref = *ptr; //&����int����refΪ���ã�*�ڱ��ʽ�У���Ϊ������
		}

		{
			int i = 10;
			//double *ptr = &i; //����ptr ��i�����Ͳ�ƥ��
		}
		{
			int i, *ptr1, *ptr2; //iΪint���ͣ�ptr1��ptr2Ϊָ�����
		}
		{
			int *ptr1 = nullptr; //ptr1Ϊ��ָ�룬û��ָ���κζ���
			int *ptr2; //ptr2ΪҰָ�룬�ǳ�Σ
		}
		{
			int *p = 0; //p Ϊ��ָ��
		}
	}
	/*���˲��ִ���������4.2.2 �ı�ָ��*/
	{
		int i = 10, j = 100;
		int *ptr1 = &i, *ptr2 = &j; //ptr1ָ��i��ptr2ָ��j
		ptr1 = ptr2; //�ı�ptr1��ָ��ʹ��ָ��j����ptr1 = &j;�ȼ�
		ptr1 = nullptr; //�ı�ptr1��ָ��ptr1��ɿ�ָ��
	}
	/*���˲��ִ���������4.2.3 const��ָ�룩*/
	{
		const int ci = 10, cj = 1;
		const int *ptrc = &ci; //ptrcָ����ci
							   //*ptrc = 0; //���󣺲����޸�ptrcָ��ĳ���ci
		ptrc = &cj; //ָ������һ������
		int i = 0;
		ptrc = &i; //������ָ��һ����const ����
				   //int *ptr = &ci; //����ptr ����ָ����
		{
			int j = 0, i = 0;
			int *const cptr = &i; //����ʱ��ʼ����cptrֻ��ָ�����i
								  //cptr = &j; //���󣺲��ܸı�cptr��ָ��
			*cptr = 10; //��ȷ������ͨ��*cptr�޸���ָ��Ķ���i��ֵ
		}
		const int *const cptrc = &ci; //cptrc��һ��ָ����ci �ĳ���ָ��
	}
	/*���˲��ִ���������4.2.4 �����Ƶ���ָ�룩*/
	{
		int i = 0;
		const int ci = 10;
		auto p = &i; //p���Ƶ�Ϊint *����
		auto pc = &ci; //pc���Ƶ�Ϊconst int * ���ͣ�ci��const���Ա�����
		auto &ref = i, *ptr = &i; //auto���Ƶ�Ϊint
								  //auto &ref2 = i, ptr2 = &i; //����auto���Ƶ����Ͳ�һ��
		{
			int i = 0, *ptr = &i;
			decltype (ptr) ptr2; //ptr2Ϊint *
			decltype (*ptr) refi = i; //��ȷ��ref iΪint &�������ʼ��
			decltype (*ptr + 0) j; //��ȷ��jΪint����
		}
	}
	/*���˲��ִ���������4.2.5 voidָ�룩*/
	{
		double x = 0;
		int i = 0;
		void *p = &x; //��ȷ�����Դ��double���Ͷ���ĵ�ַ
		p = &i; //��ȷ��Ҳ���Դ��int ���Ͷ���ĵ�ַ
		{
			double x = 0, *ptrd = &x;
			void *ptr = &x;
			ptrd = static_cast<double *>(ptr); //��Ҫǿ������ת��
		}
	}
	/*���˲��ִ���������4.2.6 �༶ָ�룩*/
	{
		int i = 1, *ptr = &i;
		int **pptr = &ptr; //��ָ�����ptr�ĵ�ַ��ʼ��pptr
		cout << i << '\t' << *ptr << '\t' << **pptr << endl;
		int ***ppptr = &pptr;
		cout << ***ppptr << endl; //���1
	}
	/*���˲��ִ���������4.2.7 ���ú�ָ�룩*/
	{
		int i = 0, j = 1, &r = i, *p = &i;
		r = 4; //�޸���r��󶨵Ķ���i��ֵ
		p = &j; //�޸�ָ��p��ֵ��ʹ��ָ��j
		{
			int i = 0;
			int *const p = &i; // ������ָ��pָ����������
			int &ri = i; //����riֻ����i��
		}
	}
	/*���˲��ִ���������4.3.1 ����Ķ���ͳ�ʼ����*/
	{
		int arr[10];
		unsigned cnt = 10;
		//int arr[cnt]; //����cnt���ǳ������ʽ
		constexpr int sz = 10; //�������ʽ����2.4.2�ڣ���18ҳ��
		int arri[sz]; //��ȷ�����10���������ݵ�����
					  //float arrf[10.]; //�������鳤�ȱ���������
		{
			int arr[5] = { 1, 2, 3, 4, 5 };
		}
		{
			int arr[5] = { 1, 2, 3 }; //�ȼ���arr[5] = {1, 2, 3, 0, 0}
		}
		{
			int arr[] = { 1, 2, 3, 4, 5 }; //����arr�ĳ���Ϊ5
		}
		{
			char name[] = "Lisha"; //�Զ�����ַ�����������\0��
		}
		{
			char name[] = { 'L', 'i', 's', 'h', 'a', '\0' };
			//	name = "Lisha"; //�������鲻����ֵ����
		}
		{
			int arr[5]; //����һ������5��int����Ԫ�ص�����
			int *arrp[5]; //����һ������5��int*����Ԫ�ص����飬ÿ��Ԫ�ض���ָ��
			int(*parr)[5] = &arr; //����һ��ָ����5��int����Ԫ�ص������ָ��
			int(&rarr)[5] = arr; //����arr��һ������
								 //parrp ��rarrp �ֱ�Ϊָ��ָ������arrp��ָ�������
			int *(*parrp)[5] = &arrp;
			int *(&rarrp)[5] = arrp;
		}
	}
	/*���˲��ִ���������4.3.2 ��������Ԫ�أ�*/
	{
		int arr[5] = { 1, 2, 3, 4, 5 };
		arr[0] = 10; //д�������޸ĵ�һ��Ԫ�ص�ֵ
		cout << arr[0] << endl; //����������ȡ��һ��Ԫ�أ�������Ϊ��10
		{
			int arr[5] = { 1,2,3,4,5 }; //���岢��ʼ��һ������5��������������
			for (auto i : arr) { //iΪarr �е�ǰԪ�صĸ���
				cout << i << endl; //��ӡ�����ǰ��ȡ������
			}
			for (auto &i : arr) { //i Ϊarr�е�ǰԪ�ص�����
				i = 0; //д������ÿһ��Ԫ������Ϊ0
			}
		}
	}
	/*���˲��ִ���������4.4.1 ָ��ָ�����飩*/
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr; //arr��ת����arr[0]�ĵ�ַ
		{
			int *p = &arr[0];
		}
		cout << arr << "," << &arr[0];//�����ǵ�ϵͳ�£����:010FF774,010FF774
		auto pa = arr; //pa Ϊint *���ͣ���Ȼ��һ��ָ��
		cout << *pa; //���arr[0]��ֵ1
		decltype(arr) ar2; //ar2 Ϊ���5����������һά����
		int a2d[3][5];
		int(*p2d)[5] = a2d; //ָ��a2d �ĵ�һ��Ԫ��
		{
			int(*p2d)[5] = &a2d[0]; //a2d ��һ��Ԫ�صĵ�ַ
		}
		{
			int *p2d[5];
		}
		{
			int * const p = &arr[0]; //arr�������Ϊconst ָ��p
			cout << sizeof(arr) << " " << sizeof(p);
		}
	}
	/*���˲��ִ���������4.4.2 ����ָ��������飩*/
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		int *p = arr; //pָ������arr
		int *p2 = p + 3; //����p�����3��Ԫ�صĵ�ַ����&arr[3]
		int *p3 = p++; //p����һ��λ�ã�p3 ָ��pԭ����λ��&arr[0]
		int *p4 = ++p; //p ��������һ��λ�ã�p4 ��pָ��ͬһ��λ��&arr[2]
		p2 = &arr[0]; //��ȷ��ָ���һ��Ԫ�أ��ȼ���p2 = arr;
		p2 = &arr[5]; //��ȷ��ָ��βԪ�غ����һ��λ�ã��ȼ���p2 = arr + 5;
		{
			int *p = arr; //p ָ������arr
			int val = *(p + 2) + 1; //�ȼ���int val = arr[2] + 1;
			int val2 = p[2]; //�ȼ���int val2 = arr[2];
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
			for (auto p = a2d; p < a2d + 3; ++p) {//p������Ϊint (*)[5]
				for (auto q = *p; q < *p + 5; ++q) {//q������Ϊint *
					cout << *q << " ";
				}
				cout << endl;
			}

			for (auto p = &a2d[0][0]; p < a2d[0] + 15; ++p) {
				if ((p - a2d[0]) % 5 == 0) //a2d[0]�ȼ���&a2d[0][0]
					cout << endl; //ÿ��ӡ5��Ԫ�غ���
				cout << *p << " ";
			}
		}
	}
	/*���˲��ִ���������4.5.1 ����ͳ�ʼ��string����*/
	{
		string str1; //Ĭ�ϳ�ʼ��������һ�����ַ���
		string str2(str1); //�ȼ���string str2 = str1; str2��str1��һ������
		string str3 = "Rosita"; //���Ƴ�ʼ��
		string str4("Rosita");//ֱ�ӳ�ʼ��
		string str5(5, 'R'); //ֱ�ӳ�ʼ����str5������ΪRRRRR
	}
	/*���˲��ִ���������4.5.2 string���ͳ��ò�����*/
	{
		string s;
		cin >> s; //�����հ��ַ�ֹͣ
		cout << s; //���s������
		getline(cin, s);
		{
			string s;
			cin >> s;
			cout << s.size() << endl;//���s�����ַ��ĸ�������s.length() �ȼ�
			if (!s.empty()) //���s �ǿգ������������
				cout << s;
		}
		string *ps = &s; //����һ��ָ�����ָ��string����s
		cout << ps->size() << endl; //ͨ��ָ�����size��Ա����
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
			s[1] = 'H'; //�Եڶ���Ԫ�ؽ���д����
			cout << s.at(1) << endl;
			cout << s.front() << " " << s.back() << endl; //��ӡ���h o
		}
	}
	/*���˲��ִ���������4.5.3 C����ַ�����*/
	{
		char cstr[] = "Hello";
		char *ps = cstr;//ָ���ַ�����cstr
		char *ps2 = "C++";
		cout << ps << "," << ps2 << endl; //���Hello,C++
		char cs[] = { 'C', '+ ', '+ ' };
		//cout << strlen(cs) << endl; //����csû���Կ��ַ�����
		char small[] = "C++", big[] = "Programming";
		//cout << strcpy(small, big) << endl; //����small �ڴ�ռ䲻��
		{
			string str = "hello";
			char carr[10];
			strcpy(carr, str.c_str());
		}
	}
	/*���˲��ִ���������4.6.1 ����ͳ�ʼ��vector ����*/
	{
		vector<int> v1; //��������Ŀ�vector
		vector<int> v2 = { 0,1,2 }; //v2������Ԫ�أ�ֵ�ֱ�Ϊ0��1��2
		vector<int> v3(10); //v3�ɴ��10��������ֵΪĬ��ֵ0
		vector<int> v4(10, 1); //v4���10������1
		vector<string> v5 = { "Hi","Lisha","Mandy","Rosita" };
		vector<vector<int>> v6(10, v2);
	}
	/*���˲��ִ���������4.6.2 vector���ͳ��ò�����*/
	{
		vector<int> vi;
		for (int i = 0; i < 100; ++i)
			vi.push_back(i);//�������100������0-99
		vi.pop_back();
		vi.clear();//�����Ƴ�����Ԫ�أ�
	}
	/*���˲��ִ���������4.6.2 vector���ͳ��ò�����*/
	{
		vector<int> vi = { 0,1,2,3 };
		auto itb = vi.begin();//itbָ��vi�ĵ�һ��Ԫ��
		auto ite = vi.end();//iteָ��vi��β��Ԫ��
		cout << *itb << endl; //�����һ��Ԫ��ֵ0
		for (auto it = vi.begin(); it != vi.end(); ++it) {
			*it *= 2; //ÿ��Ԫ�س�2
			cout << *it << endl;
		}
		vector<string> vs = { "Hi","Lisha","Mandy","Rosita" };
		for (auto it = vs.begin(); it != vs.end(); ++it) {
			cout << (*it).size() << endl;//ѡ��string���Ա����size
		}
		//*it.size()��//���󣺵�����itû�г�Ա����size���൱��*(it.size());
		for (auto it = vs.begin(); it != vs.end(); ++it) {
			cout << it->size() << endl;
		}
	}
	/*���˲��ִ���������4.7 ö�����ͣ�*/
	{
		{
			const int red = 0;
			const int green = 1;
			const int blue = 2;
		}
		{
			enum color { red, green, blue };
			//	enum emotion { happy, calm, blue };//����ö�ٳ�Աblue�Ѿ������
			enum class stoplight { red, green, yellow };
			color c = red;//��ȷ�����Է���color���͵�ö�ٳ�Ա
						  //stoplight a = red; //����stoplight���͵�ö�ٳ�Աred�ڴ˲��ɷ���
						  //��color���͵�red��stoplight���Ͳ�ƥ��
			stoplight b = stoplight::red; //��ȷ
			enum class week {
				Sunday = 7, Monday = 1, Tuesday, Wednesday,
				Thursday, Friday, Saturday
			};
			//color c1 = 1;//�������Ͳ�ƥ��
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

