#include "stdafx.h"
#include "Detector.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int Detector::globalCount = 0;

Detector::Detector()
{
	this->myCount = globalCount;
	++Detector::globalCount;
	cout << "Detector(); address: " << this << ";";
	cout << " myCount: " << this->myCount << endl;
}


Detector::~Detector()
{
	cout << "~Detector(); address: " << this << ";";
	cout << " myCount: " << myCount << endl;
}

unsigned int Detector::getMyCount()
{
	return 0;
}

