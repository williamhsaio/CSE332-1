#include "stdafx.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
Student::Student(string n, float g) : name(n), gpa(g) {}
bool Student::operator< (const Student &S) const
{
	return name < S.name;
}
// << operator for a Student
ostream &operator<<(ostream &o, const Student &S)
{
	o << S.name << " " << S.gpa;
	return o;
}
bool StudentCompare::operator()(const Student &S1,
	const Student &S2)
{
	return (S1.name < S2.name) ||
		(S1.name == S2.name && S1.gpa < S2.gpa);
}