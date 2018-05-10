
#pragma once
#include "Animal.h"
#include <list>
class Zoo
{
	friend std::ostream & operator<<(std::ostream&o, const Zoo &z);

public:
	static Zoo * instance();
	void add(Animal * a);
	virtual ~Zoo();
private:
	std::list<Animal *> animals_;
	static Zoo * zoo_;
	Zoo();
	Zoo(Zoo &z);
	Zoo operator=(Zoo &z);
};

std::ostream & operator<<(std::ostream & o, const Zoo &z);