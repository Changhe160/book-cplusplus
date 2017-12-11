/**************************************************************************
Copyright: Yongfeng Liu
Author: Yongfeng Liu
Date: 2017-06-20
Description:A simple calculator based on stack
**************************************************************************/

#include <string>
#include <iostream>
#include "Calculator.h"

using namespace std;

int main(){
	string exp;
	Calculator cclt;
	while (getline(cin, exp)){
		cout << cclt.doIt(exp) << endl;
	}	

	system("pause");
    return 0;
}

