#include "stdafx.h"
#include "new1.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
/*
new2::new2() :m_(0){
	
	cout << " default set m = " << 0 << endl;
}
*/
int add(int a, int b) {
	return a + b;
}

long add(long a, long b) {
	return a + b+1;
}
new2::new2(int i ) :m_(0){
	m_ = i;
	cout << "new set m = " << i << endl;
}
ostream & operator<<
(ostream &out, const new2 &a) {
	out << "this::m_ = " << a.m_;
	return out;
}

new2 & new2::operator= (const new2 &another) {
	if (this == &another) {
		return *this;
	}
	this->m_ = another.m_;
	return *this;
}
const new2 new2::operator+ (const new2 &another) {
	new2 temp;
	temp.m_ = this->m_ + another.m_;
	return temp;
}
const bool new2::operator< (const new2 &another) {
	if (this->m_ < another.m_) {
		return true;
	}
	return false;
}
const bool new2::operator== (const new2 &another) {
	if (this->m_ == another.m_) {
		return true;
	}
	return false;
}
