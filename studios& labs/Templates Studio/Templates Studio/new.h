#pragma once
#include "stdafx.h"
#ifndef new
#define new
#include <vector>
#include <iostream>

using namespace std;
template <typename s, typename s1>
s add(s a, s1 b) {
	return a + b;
}

template <typename Iterator>
size_t counting(Iterator begin, Iterator end)
{
	size_t answer = 0;
	while (begin != end) {
		++answer;
		begin = begin + 1;
	}

	return answer;
}


//ostream &operator<<(ostream & o, const new2 &a);
#endif