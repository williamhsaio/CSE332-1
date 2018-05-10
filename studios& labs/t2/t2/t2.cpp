// t2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "q2.h"
#include <array>
#include <vector>
#include <list>
#include <iostream>

int main()
{
	const int* a111;
	int b111 = 11;
	a111 = &b111;
	//int &aaaa;
	int *aaaaaaa;

	using namespace std;
	// Exercise 2
	array<int, 5> a = { 1, 2, 3, 4, 5 };
	list<int> v;
	v.push_back(1);
	v.push_back(2);
	//int c = a[4];
	//cout << c << endl;
	size_t arraySize = exercise2(&a, &a+5);
	size_t listSize = exercise2(v.begin(), v.end());
	cout << "Array (5) size: " << arraySize << '\n';
	cout << "List (2) size: " << listSize << '\n';

	// Exercise 3

	// Exercise 4

	// Exercise 5

	//Exercise 6
	
	cout << "\n\n";
	array<char, 5> c = { 'a', 'b', 'c', 'd', 'e' };
	char * cBegin = &c[0];
	char * cEnd = &c[4] + 1;
	cout << "Array (5) of chars size: " << exercise2(cBegin, cEnd) << '\n';

	cout << endl;
	
    return 0;
}

