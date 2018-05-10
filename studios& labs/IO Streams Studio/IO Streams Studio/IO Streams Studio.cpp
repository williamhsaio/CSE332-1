// Classes Studio_2_12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
using namespace std;
#include "Header1.h"
#include <sstream>
#include <fstream>
#include <string>

ostream & operator<< (ostream &o,
	const Point2D &p) {
	o << p.x() << " " << p.y(); // space delimited
	return o;
}

istream & operator >> (istream &i, Point2D &p) {
	i >> p.x_ >> p.y_; // extract both variables
	return i;
}



void baz(const int & j)
{
	cout << j << endl;
}

int main(int argc, char *argv[])
{	
	int o = 7;
	baz(o);

	Point2D const c = Point2D(2, 3);
	Point2D x;

	x = x.change_x(8);
	c.x();
	//vector<Point2D> v;
	//v.push_back(c);

	//cout << v[0] << endl;
	cout << x.x() << endl;
	//cout << i.x() << endl;

	Point2D m; // default construction
	cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
	m.change_x(7).change_y(3); // chained use of mutator functions
	cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
	Point2D n(m); // copy construction
	cout << "n.x = " << n.x() << " and n.y = " << n.y() << endl;
	Point2D d = Point2D(2, 1);
	//cout << d << endl;
	//while (true) {
	//	Point2D p(0, 0);
	//	cout << "Please enter 2 coordinates(or hit Ctrl - C to quit) : ";
	//		cin >> p;
	//	cout << endl
	//		<< "You entered "
	//		<< p << endl;
	//}

	ifstream ifs;
	string filename = argv[1];
	string outputname = argv[2];
	ifs.open(filename);
	ofstream ofs(outputname);
	if (!ifs.is_open())
	{
		cout << "the file: " << filename << " can't be opened or can't be found for reading" << endl;
		return -1;
	}
	if (!ofs.is_open())
	{
		cout << "the file: " << argv[2] << " can't be opened for writing" << endl;
		return -2;
	}
	int i = 0;
	while (!ifs.eof())
	{
		i++;
		//printf("%d\n",i);
		string line;
		//ifs >> line;
		//if (line == "" || line == " ") {
		//	break;
		//}
		Point2D p(0, 0);
		ifs >> p;
		ofs << p;
		ofs << " ";

	}

	
	
	

	return 0;
}