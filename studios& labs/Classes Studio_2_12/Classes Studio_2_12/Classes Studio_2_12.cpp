// Classes Studio_2_12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;
#include "struct.h"





int main(int argc, char *argv[])
{	
	int i = 7;
	int &k = i;
	cout << k << endl;





	int qp = 2;
	int pq = 3;
	if (qp =pq) {
		cout << "=" << endl;
	}

	cout << argv[0] << endl;
	Point2D const c =  Point2D(2, 3);
	Point2D x;
	
	x = x.change_x(8);
	c.x();
	//vector<Point2D> v;
	//v.push_back(c);

	//cout << v[0] << endl;
	//cout << x.x() << endl;
	//cout << i.x() << endl;


	char cString[13] = "midterm exam";
	char * cP = &cString[3];
	cout << cP << endl; // 1
	cout << *cP << endl; // 2
	cout << cP + 5 << endl; // 3
	
	string b = "world";
	string a = "hello";
	if (a < b) {
		cout << "a>b" << endl;

	}
	//cout << *p << endl;
	//cout << u << endl;



	Point2D m; // default construction
	cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
	m.change_x(7).change_y(3); // chained use of mutator functions
	cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
	Point2D n(m); // copy construction
	cout << "n.x = " << n.x() << " and n.y = " << n.y() << endl;

    return 0;
} 





