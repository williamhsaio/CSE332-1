// midterm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <set>
#include <iterator>
#include <numeric>
using namespace std;

void func1(int a, int b) {
	cout << "version 1" << endl;
	b = 100;
	a = 100000;
}
void func1(int *a, int *b) {
	cout << "version 2" << endl;
	int temp = *b;
	*b = *a;
	*a = temp;
}
void func2(int & a, int & b) {
	cout << "version 3" << endl;
	int temp = b;
	b = a;
	a = temp;
}

int main(int argc, char * argv[])
{/*
	int i = 10;
	int j = 20;
	func1(&i, &j);
	cout << "i: " << i << " j : " << j << endl;
	
	int i = 10;
	int j = 20;
	func2(i, j);
	cout << "i: " << i << " j : " << j << endl;
	*/
	//int i = 10;
	//int j = 20;
	//func1(i, j);
	//cout << "i: " << i << " j :  "<< j << endl;
	int i = 10;
	int j = 20;
	int & r = j;
	r = i;
	cout << "i: " << i << " j : " << j;

	vector<string> v = { "fall ", "2017 ", "midterm" };
	string s;
	ostream_iterator<string> out(cout, "\n");
	string result = accumulate(v.begin(), v.end(), s);
	cout << result << endl;
}