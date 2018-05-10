#include "stdafx.h"
#pragma once

class Detector
{
public:
	static unsigned int globalCount;
	unsigned int myCount;
	Detector();
	~Detector();
	unsigned int getMyCount();

};

class Wrapper
{
private:
	Detector * detector_;
	bool b_;
public:
	Wrapper();
	Wrapper(const Wrapper & w);
	Wrapper & operator=(const Wrapper & w);
	virtual ~Wrapper();
	Wrapper(Wrapper &&w);
	Wrapper operator=(Wrapper &&w);
};
