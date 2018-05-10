#include "stdafx.h"
#include "Zoo.h"

Zoo * Zoo::zoo_ = 0;

Zoo * Zoo::instance() {
	if (zoo_ == 0) {
		zoo_ = new Zoo;
	}
	return zoo_;
}

void Zoo::add(Animal * a)
{
	animals_.push_back(a);
}


Zoo::Zoo()
{
}


Zoo::~Zoo()
{
}

std::ostream & operator<<(std::ostream & o, const Zoo & z)
{
	for (auto animal = z.animals_.begin(); animal != z.animals_.end(); ++animal) {
		(*animal)->print(o);
	}
	return o;
}