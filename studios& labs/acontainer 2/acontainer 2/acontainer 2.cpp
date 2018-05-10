#include "stdafx.h"

#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main(int argc, char * argv[])
{

	set <string> a;
	bool s1 = a.insert("I").second;
	auto s2 = a.insert("like");
	auto s3 = a.insert("banana");
	auto s4 = a.insert("I");


	cout << s1 << endl;
	cout << s4.second << endl;

	multiset <string> b;
	auto b0 = b.insert("Hi");
	b.insert("nice");
	auto b1 = b.insert("shuo");
	auto b2 = b.insert("like");
	auto b3 = b.insert("banana");
	auto b4 = b.insert("shuo");
	b.insert("shuo");
	b.insert("shuo");
	b.insert("ssss");
	auto k = b.equal_range("shuo");
	b.erase(++k.first, k.second);

	ostream_iterator<string> o(cout, "\n");
	ostream_iterator<string> g(cout, "\n");
	//copy(k.first.operator++, k.second.operator--, o);
	//cout << *(--k.first) << endl;
	//cout << *k.second << endl;
	auto s = b.equal_range("shuo");
	cout << "print the same string :" << endl;
	copy((s.first), (s.second), o);
	cout << "print all :" << endl;
	copy(b.begin(), b.end(), g);
	//cout << (int)(k.second-k.first)<< endl;
	/*
	//question 6
	cout << endl;
	cout << endl;

	multimap <string, int> m;
	m.insert({ "C", 5 });
	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));
	m.insert(make_pair("c", 10));
	m.insert(make_pair("c", 11));
	m.insert(make_pair("c", 12));
	m.insert(make_pair("d", 5));
	auto ee =m.equal_range("c");

	ostream_iterator<string> m1(cout, "\n");
	ostream_iterator<string> m2(cout, "\n");

	cout << "print the same string :" << endl;
	copy((ee.first), (ee.second), m1);
	cout << "print all :" << endl;
	copy(m.begin(), m.end(), m2);
	*/

	return 0;
}


