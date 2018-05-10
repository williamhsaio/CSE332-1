
#pragma once
#include "Animal.h"
class Ostrich :
	public Animal
{
public:
	Ostrich();
	virtual ~Ostrich();
	virtual void print(std::ostream &o) const override;
};
