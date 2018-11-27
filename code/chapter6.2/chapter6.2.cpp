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

	Employee(const string &name) :Employee(0, name) {//ί�й��캯��
	
	}

	Employee(const Employee &) = delete;

};

int main() {
	//6.2.1
	{
		Fraction a;			//Ĭ�Ϲ��캯��
		Fraction b(1, 5);	//ֱ�ӳ�ʼ��
		int i;
		Foo f(i);
		
		Employee member("Kevin"); 
	}
	//6.2.2
	{
		Fraction a(1, 5);	//ֱ�ӳ�ʼ��
		Fraction b(a);		//ֱ�ӳ�ʼ����bΪ����a�Ŀ���
		Fraction c = Fraction(3, 2); //���Ƴ�ʼ��
		Fraction d = 7;		//���Ƴ�ʼ��

		//Fraction d2 = static_cast<Fraction>(7); //�����ǽ� Fraction ���Ĭ�Ϲ��캯������Ϊ explicit ֮��

		Fraction e = divide(b, c);

		Employee e1;
		//Employee e2(e1);//���󣺲��ܵ���ɾ���ĸ��ƹ��캯��
	}
}