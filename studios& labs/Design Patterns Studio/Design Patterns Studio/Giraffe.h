#pragma once

#include "Animal.h"
class Giraffe :
	public Animal
{
public:
	Giraffe();
	virtual ~Giraffe();
	virtual void print(std::ostream &o) const override;
};
