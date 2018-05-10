#include "stdafx.h"
#include "Wrapper.h"
#include "Detector.h"
#include <memory>
#include <iostream>


Wrapper::Wrapper()
{
	this->detector_ = 0;
	this->detector_ = new Detector;

	b_ = true;
}

Wrapper::Wrapper(const Wrapper &w)
{
	using namespace std;
	cout << "Copy constructor start" << endl;
	cout << "Global count at start: " << w.detector_->globalCount << endl;
	cout << "Original count at start: " << w.detector_->myCount << endl;
	//cout << "Copy count at start: " << this->detector_->myCount << endl;
	this->detector_ = w.detector_;
	this->b_ = false;
	cout << "Global count at end: " << w.detector_->globalCount << endl;
	cout << "Original count at end: " << w.detector_->myCount << endl;
	cout << "Copy count at end: " << this->detector_->myCount << endl;
	cout << "Copy constructor end" << endl;
}

Wrapper & Wrapper::operator=(const Wrapper & w)
{
	using namespace std;
	cout << "Copy-assignment constructor start" << endl;
	cout << "Global count at start: " << w.detector_->globalCount << endl;
	cout << "Original count at start: " << w.detector_->myCount << endl;
	//cout << "Copy count at start: " << this->detector_->myCount << endl;
	if (this != &w) {

		Wrapper n = Wrapper(w);
		std::swap(n.detector_, detector_);
		std::swap(n.b_, b_);
	}
	cout << "Global count at end: " << w.detector_->globalCount << endl;
	cout << "Original count at end: " << w.detector_->myCount << endl;
	cout << "Copy count at end: " << this->detector_->myCount << endl;
	cout << "Copy-assignment constructor end" << endl;
	return *this;
}


Wrapper::~Wrapper()
{
	if (b_)
	{
		delete detector_;
	}
}

Wrapper::Wrapper(Wrapper && w) : detector_(w.detector_), b_(w.b_)
{
	w.detector_ = nullptr;
	w.b_ = true;
}

Wrapper Wrapper::operator=(Wrapper && w)
{
	using namespace std;
	cout << "Move assignment" << endl;
	if (this != &w) {
		delete detector_;
		detector_ = w.detector_;
		b_ = w.b_;
		w;
		w.detector_ = nullptr;
		w.b_ = true;
	}
	return *this;
}