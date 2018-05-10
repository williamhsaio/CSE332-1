#pragma once
#pragma once
#ifndef h1
#define h1
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class A {
public:
	virtual ~A();
	A(int i);
	  void q3();
private:
	int m_i;

};
class B : public A {
public:
	virtual ~B();
	B(int i, int j);
	 void q3();
private:
	int m_j;
};
void call1(B b) ;
void call2(B &b);
void call3(A &a);
void call4(A a);
void call5(A* a);
#endif