#include "stdafx.h"
#include "detector.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
using namespace std;

unsigned int detector::b=0;

detector::detector(): a(b)
{
	++detector::b;
	// (1) The default constructor should initialize the nonstatic
	//member variable with the value of the static member variable, then increment the value of the static
	//	member variable, and print out a message(to cout) with the method name, the object’s address, and the
	//	value of the initialized non - static member variable
	cout << "detector sonctructor" << endl;
	cout << "address : " << this << endl;
	cout <<"a value : "<< a << endl;
}
	
detector::~detector() {
	cout << "detector desturctor" << endl;
	cout << "address : " << this << endl;
	cout << "the value : " << a << endl;
}

unsigned int detector::get_a() {
	return this->a;
}


