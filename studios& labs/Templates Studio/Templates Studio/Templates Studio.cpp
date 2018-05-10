// Templates Studio.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>
#include "new.h"
#include "new1.h"
using namespace std;

int main()
{
	array<int,5> a = { 1,2,3,4,5 };
	int numbers[] = { 0, 9, 2, 7, 4, 5, 6, 3, 8, 1 };
	//int a1[10];
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);
	cout << 1 << endl;
	cout << "vetcor size is : "<<counting(v1.begin(), v1.end()) << endl;
	cout << "array size is : " << counting(a.begin(), a.end()) << endl;
	cout << counting(begin(numbers), end(numbers)) << endl;
	cout << "problem 3" << endl;
	int a13 = 1;
	question3<int> a1('b');
	question3<char> c2('a');
	
	char c13 = 'ab';
	const char c1_value =  c13;
	question3<char> c1(c1_value);
	cout << "c13 : "<<c13 << endl;
	cout << a1 << endl;
	cout << sizeof(c2) << endl;
	cout << endl;
	cout << sizeof(a13) << endl;
	cout << sizeof(c13) << endl;
	cout << "problem 3 finished" << endl;
	question3<int> smallInt1(1);
	question3<int> smallInt2(1);
	question3<int> bigInt(100);
	question3<char> smallChar1('a');
	question3<char> smallChar2('a');
	question3<char> bigChar('b');
	cout << std::boolalpha;
	cout << "1 == 1: " << (smallInt1 == smallInt2) << '\n';
	cout << "1 == 100: " << (smallInt1 == bigInt) << '\n';
	cout << "1 < 1: " << (smallInt1 < smallInt2) << '\n';
	cout << "1 < 100: " << (smallInt1 < bigInt) << '\n';

	cout << "a == a: " << (smallChar1 == smallChar2) << '\n';
	cout << "a == b: " << (smallChar1 == bigChar) << '\n';
	cout << "a < a: " << (smallChar1 < smallChar2) << '\n';
	cout << "a < b: " << (smallChar1 < bigChar) << '\n';
	cout << endl;
	cout << '\n' << '\n';

	question3<int> bigIntCopy(bigInt);
	question3<int> bigIntAssigned = bigInt;
	question3<char> bigCharCopy(bigChar);
	question3<char> bigCharAssigned = bigChar;
	cout << "Copy of 100: " << bigIntCopy << '\n';
	cout << "Assignment of 100: " << bigIntAssigned << '\n';
	cout << "Copy of b: " << bigCharCopy << '\n';
	cout << "Assignment of b: " << bigCharAssigned << '\n';
	cout << "-----------" << endl;
	long a10 = 10;
	int b10 = 21;
	int c = add(a10, b10);
    return 0;
}

