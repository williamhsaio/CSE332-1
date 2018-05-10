#pragma once
#include "stdafx.h"
#ifndef new1
#define new1
#include <vector>
#include <iostream>
using namespace std;
class new2 {
	friend  ostream & operator<<(ostream & o, const new2 &a);

private:
	int m_;
public:
	//new2();
	new2(int i =0);

	const bool operator< (const new2 &another);
	const bool operator== (const new2 &another);

	
	const new2 operator+ (const new2 &another);
	new2 & operator= (const new2 &another);
};
int add(int a, int b);
long add(long a, long b);
//ostream &operator<<(ostream & o, const new2 &a);
#endif