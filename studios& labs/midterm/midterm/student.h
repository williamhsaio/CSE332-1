#pragma once
#pragma once
#ifndef student
#define student
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	Student(string n, float g);
	string name;
	float gpa;
	bool operator< (const Student &S) const;
};
ostream &operator<<(ostream &o, const Student
	&S);
struct StudentCompare {
	bool operator()(const Student &S1,
		const Student &S2);
};

#endif