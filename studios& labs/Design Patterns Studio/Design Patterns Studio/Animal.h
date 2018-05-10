#pragma once

#include <iostream>
class Animal
{
public:
	virtual void print(std::ostream &o) const = 0;
};
