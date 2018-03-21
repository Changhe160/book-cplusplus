#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class MyStr {
	int m_length;               // length of the string
	char * m_buff;              // pointer to strorage
public:
	MyStr(const char* init_val=nullptr);
	MyStr(const MyStr &rhs);
	MyStr(MyStr &&rhs);

	~MyStr() { delete[] m_buff; }
	int size() { return m_length; }
	MyStr& operator= (const MyStr &rhs);
	MyStr& operator= (MyStr &&rhs);

	MyStr& operator+= (const MyStr& rhs);
	friend ostream& operator<< (ostream&, const MyStr&);
	friend MyStr operator+(const MyStr& s1, const MyStr& s2);
private:
	int strlen(const char * ptr);
	void strncpy(char *dest, const char * src, int n);
};
#endif


