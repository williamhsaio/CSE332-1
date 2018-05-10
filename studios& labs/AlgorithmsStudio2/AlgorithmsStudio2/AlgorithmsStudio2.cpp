// AlgorithmsStudio2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <list>
#include <deque>
#include <forward_list>
#include <functional>

using namespace std;

struct odd {
	bool operator() (int a,int b )  {
		return a>b;
	}
};

bool  greater1(int a, int b) {
	return a>b;
}
int main(int argc, char * argv[])
{
	int arr[5] = { 2, 7, 14, 5, 9 };
	int valueCounter;
	deque<int> d;
	list<int> l;
	forward_list<int> f;
	vector<int> v;
	ostream_iterator<int> o(cout, " ");
	for (int i  = 0; i < 5; ++i) {
		d.push_back(arr[i]);
		l.push_back(arr[i]);
		f.push_front(arr[i]);
		v.push_back(arr[i]);
	}
	deque<int>::iterator di = d.begin();
	list<int>::iterator li = l.begin();
	forward_list<int>::iterator fi = f.begin();
	vector<int>::iterator vi = v.begin();
	cout << "third element in deque: " << endl;
	di = di + 2;
	cout << *di << endl;

	cout << "third element in list: " << endl;
	li = ++(++li);
	cout << *li << endl;
	cout << "third element in forward list : " << endl;
	fi = ++(++fi);
	cout << *fi << endl;
	cout << "third element in deque: " << endl;
	vi = vi+2;
	cout << *vi << endl;
	ostream_iterator<int> t(cout, " ");
	deque<int> d1;
	d1.push_back(100);

	deque<int>::iterator dii(d1.begin());
	cout << "first 1" << endl;
	copy(d1.begin(),d1.end(),t);

	cout << endl;
	cout << "first 2" << endl;
	copy(d1.begin(), d1.begin(), t);
	cout << endl;
	cout << "first 3" << endl;
	copy(d1.begin()+1, d1.begin()+2, t);
	cout << endl;
	cout << "first 4" << endl;
	copy(d1.end(), d1.end(), t);
	cout <<"1hi"<< endl;
	int arr1[] = { -2, 19, 80, -47, 80, 80, -2 };
	int *start = arr1;
	int *end = arr1 + 7;
	copy(start, end, t);
	cout << "hello"<<endl;
	int arr2[] = { -2, 19, 80, -47, 80, 80, -2 };
	int * start1 = arr2;
	int* end1 = arr2 + 7;
	sort(start1, end1, odd());
	copy(start1, end1, t);
    return 0;
}

