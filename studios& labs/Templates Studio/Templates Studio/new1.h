#pragma once
#include "stdafx.h"
#ifndef new1
#define new1
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
struct question3
{
	T newx_value;
	question3(const T& value123) :newx_value(value123){};
	bool operator==(const question3<T> &t) const {
		return newx_value == t.newx_value;
	}
	bool operator<(const question3<T> &t) const {
		return newx_value < t.newx_value;
	}

};

template <typename oper>

ostream & operator<<(ostream & o, const question3<oper> &a) {
	o << a.newx_value << endl;
	return o;
};

#endif