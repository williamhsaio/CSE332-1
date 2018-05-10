// Design Patterns Studio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Animal.h"
#include "Ostrich.h"
#include "Giraffe.h"
#include "Zoo.h"
#include <vector>
#include <list>


// Exercise 3
template <typename TYPE> void print(TYPE &container, std::ostream &o) {
	for (auto index = container.begin(); index != container.end(); ++index) {
		(*index)->print(o);
	}
}

int main()
{
	using namespace std;

	// Exercise 2
	vector<Animal *> v;
	Ostrich * op = new Ostrich;
	Giraffe * gp = new Giraffe;
	v.push_back(op);
	v.push_back(gp);
	size_t index;
	for (index = 0; index < v.size(); ++index) {
		v[index]->print(cout);
	}

	// Exercise 3
	list<Animal *> l;
	l.push_back(op);
	l.push_back(gp);
	print(l, cout);
	print(v, cout);

	// Exercise 4
	cout << "\n\n";

	Giraffe * g1 = new Giraffe;
	Ostrich * o1 = new Ostrich;
	Zoo * z = Zoo::instance();

	z->add(g1);
	z->add(o1);
	cout << *z;

	cout << "waiting..." << endl;
	std::getchar();
	return 0;
}

