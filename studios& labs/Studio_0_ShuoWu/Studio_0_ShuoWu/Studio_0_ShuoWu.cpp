// Studio_0_ShuoWu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{	
	cout << "hello, world!" << endl;
	string a;
	a = a + "shuoWu,";
	a = a + "han.yang";
	printf("%s\n", a.c_str());
	//cout << a << endl;
	size_t b;
	b = a.length();
	

	printf("%d\n", b);
    return 0;
}


