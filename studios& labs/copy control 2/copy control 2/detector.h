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
