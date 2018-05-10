// Object Oriented Programming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "h1.h"
using namespace std;

int main(int argc, char *argv[])
{

	A a1(5);
	B b1(4,5);
	A & ar1 = a1;
	A & ar2 = b1;
	B & br1 = b1;
	//q 3
	cout << "q3 a1" << endl;
	a1.q3();
	cout << "q3 b1" << endl;
	b1.q3();
	cout << "q3 ar1" << endl;
	ar1.q3();
	cout << "q3 ar2" << endl;
	ar2.q3();
	cout << "q3 br1" << endl;
	br1.q3();
	//q4
	cout << endl;
	A * ap1 = &ar1;
	A * ap2 = &ar1;
	B * bp1 = &br1;
	cout << endl;
	cout << endl;
	cout << "q3 ap1" << endl;
	ap1->q3();
	cout << "q3 ap2" << endl;
	ap2->q3();
	cout << "q3 ap2" << endl;
	(*ap2).q3();
	cout << "q3 bp1" << endl;
	bp1->q3();
	//q5 
	A a2(3);
	B b2(1, 2);
	cout << endl;

	A* apointer1 = new A(2);
	A* apointer2 = new A(2);
	A* newpointer1 = &b2;
	B* bpointer1 = new B(3,4);
	cout << endl;
	delete apointer1;
	cout << endl;
	delete apointer2;
	cout << endl;
	delete bpointer1;
	cout << "1" <<endl;
	//call1(b2);
	call2(b2);
	cout << "2" << endl;
	call3(a2);
	call4(a2);
	cout << "3" << endl;
	call5(newpointer1);
	cout << "4" << endl;
    return 0;
}

