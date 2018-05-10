// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "h1.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
using namespace std;

A::~A() {
	cout << "A destructor" << endl;
}

A::A(int i): m_i(i){
	cout << "A constructor" << endl;
}

 void A::q3()
{
	cout << "a q3" << endl;
	
}

B::~B() {
	cout << "b destructor" << endl;
}

B::B(int i, int j ):m_j(i),A(j) {
	cout << "b constructor" << endl;
}

 void B::q3()
{
	cout << "b q3" << endl;
	
}
 void call1(B b) {
	 b.q3();
 }
 void call2(B &b) {
	 b.q3();
 }
 void call3(A &a) {
	 a.q3();
 }
 void call4(A a) {
	 a.q3();
 }
 void call5(A *a) {
	 (*a).q3();
 }

