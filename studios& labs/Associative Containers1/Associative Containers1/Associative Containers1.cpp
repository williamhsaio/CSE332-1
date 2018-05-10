//

#pragma once
#include "stdafx.h"
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

bool Compare(string const &a, string const &b) {
	return a > b;
}
struct test{
	bool operator ()(string const &a, string const &b) {
		return a > b;
	}

};

int main(int argc, char * argv[]) 
{	
	set <string> a;
	ostream_iterator<string> o(cout, "\n");
	//a.insert(argv, argv + argc);
	auto neww = inserter(a ,a.end());
	copy(argv, argv + argc, neww);
	copy(a.begin(), a.end(),o);
	cout << endl;

	set<char*> q3;
	ostream_iterator<string> t(cout, "\n");
	//a.insert(argv, argv + argc);
	auto new1 = inserter(q3, q3.end());
	copy(argv, argv + argc, new1);
	copy(q3.begin(), q3.end(), t);

	cout << "question 6" << endl;

	//set <string, test> q6;
	set<string, bool(*)(const string& a, const string& b)> q6(&Compare);
	ostream_iterator<string> l(cout, "\n");
	//a.insert(argv, argv + argc);
	auto w = inserter(q6, q6.end());
	
	copy(argv, argv + argc, w);
	copy(q6.begin(), q6.end(), l);
	cout << endl;


    return 0;
}

