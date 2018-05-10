// Overloading Studio.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "new1.h"
using namespace std;

int main()
{
	
	new2 a1;
	
	cout << a1 << endl;
	
	
	new2 a(5);
	new2 b(4);
	new2 c(3);
	new2 d(2);
	cout << a << b << endl;
	cout << (a +b)<< endl;
	cout <<( b< a) << endl;
	cout << (a = b=c) << endl;
	/*
	vector< new2> v_new2;
	v_new2.push_back(a1);
	v_new2.push_back(a);
	v_new2.push_back(b);
	v_new2.push_back(c);
	sort(v_new2.begin(),v_new2.end());
	for (size_t i = 0; i < v_new2.size();i++) {
		cout << i+1<<" th element is : "<<v_new2[i] << endl;
	}
	*/
	cout << "test" << endl;
	int aa = 10;
	int bb = 11;
	long cc = add(aa, bb);
	cout << cc << endl;
	return 0;

}

