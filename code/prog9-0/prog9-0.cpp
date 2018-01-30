#include<iostream>
#include <string>
using namespace std;

class Mamal {
protected:
	string m_name;
public:
	virtual void sounding() = 0;
};

class Dog :public Mamal {
protected:
	void bark() {
		cout << "barking" << endl;
	}
public:
	void sounding() override {
		bark();
	}
};

class Cat :public Mamal {
protected:
	void meow() {
		cout << "meowing" << endl;
	}
public:
	void sounding() override {
		meow();
	}
};

int main() {
	Cat c;
	c.sounding();
}