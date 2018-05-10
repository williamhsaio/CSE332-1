
#pragma once
#include "Detector.h"
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
