#include<iostream>
#include<memory>
#include<vector>
#include"MyStr.h"
using namespace std;

int main() {

	{//8.2.1
		{
			MyStr s("dynamic memory"); //ִ�й��캯��
			cout << s << endl; //��ӡ���dynamic memory
		} 
	}

	{//8.2.2
		MyStr s1("dynamic"), s2(s1), s3;
		s3 = s1;
	}

	{//8.2.3
		MyStr s1("move "), s2("constructor");
		MyStr s3(s1 + s2);
	}
	{//8.2.3
		MyStr s1("move "), s2("assignment"), s3;
		s3 = s1 + s2;
	}
}