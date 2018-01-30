#include"MyString.h"


MyStr& MyStr::operator= (const MyStr &rhs)
{
	if (this != &rhs){          // guard against  a = a;  
		delete[] m_buff;              // release old memory & then
		m_length = rhs.m_length;       // allocate new memory 
		m_buff = new char[m_length];
		strncpy(m_buff, rhs.m_buff, m_length);
	}
	return *this;                  // return a reference to itself
}

MyStr::MyStr(const char* init_val) :m_length(strlen(init_val)),
m_buff(m_length>0?new char[m_length]:nullptr){
	strncpy(m_buff, init_val,m_length);
}

MyStr::MyStr(const MyStr& rhs) :m_length(rhs.m_length),
m_buff(m_length>0 ? new char[m_length] : nullptr)
{
	strncpy(m_buff, rhs.m_buff,m_length);
}

MyStr::MyStr(MyStr && rhs): m_length(rhs.m_length),m_buff(rhs.m_buff) {
	rhs.m_buff = nullptr;
	rhs.m_length = 0;
}

MyStr& MyStr::operator= (MyStr &&rhs) {
	if (this != &rhs) {
		delete[] m_buff;
		m_length = rhs.m_length;
		m_buff = rhs.m_buff;
		rhs.m_buff = nullptr;
		rhs.m_length = 0;
	}
	return *this;
}
MyStr& MyStr::operator+= (const MyStr& rhs) {	
	char *buf = new char[m_length + rhs.m_length];
	strncpy(buf,m_buff, m_length);
	strncpy(buf+ m_length, rhs.m_buff, rhs.m_length);      
	m_length += rhs.m_length;       
	delete[] m_buff;

	m_buff = buf;
	return *this;
}

int MyStr::strlen(const char * ptr) {
	int len = 0;
	while (ptr&&*ptr++ != '\0')
		++len;
	return len;
}

void MyStr::strncpy(char *dest, const char *src, int n) {
	for (int i = 0; i < n; i++)
		dest[i] = src[i];
}

// implement the other two guys yourself

ostream& operator << (ostream& os, const MyStr& s)
{
	// print char after char from m_buff
	for (int i = 0; i < s.m_length; i++)  os<<s.m_buff[i];
	return os;         // this is to allow multiple <<, as in  cout << a << b;
}

MyStr operator+(const MyStr& s1, const MyStr& s2)
{
	MyStr res;
	res.m_length = s1.m_length + s2.m_length;
	res.m_buff = new char[res.m_length];
	MyStr::strncpy(res.m_buff, s1.m_buff, s1.m_length);
	MyStr::strncpy(res.m_buff + s1.m_length, s2.m_buff, s2.m_length);

	return res;
}


