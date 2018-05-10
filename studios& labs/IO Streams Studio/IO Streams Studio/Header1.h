#pragma once
#include <string>
#include <iostream>
using namespace std;

class Point2D {
	friend istream &operator>>(istream &i, Point2D &p);

public:

	Point2D();
	Point2D(int x, int y);
	Point2D(const Point2D &d);
	//Point2D &t;
	int x() const {
		return x_;
	}
	int y() const {
		return y_;
	}
	Point2D & change_x(int x) {
		x_ = x;
		return *this;
	}

	Point2D & change_y(int y) {
		y_ = y;
		return *this;
	}
	
	// operator< (const Point2D &) const;
	//char operator << (const Point2D &)  const;
private:
	int x_;
	int y_;
};
Point2D::Point2D()
	:x_(0), y_(0)
{}
Point2D::Point2D(int x, int y)
	: x_(x), y_(y)
{}
Point2D::Point2D(const Point2D &d)
	: x_(d.x_), y_(d.y_)
{}
ostream & operator<< (ostream &,
	const Point2D &);
istream & operator >> (istream &, Point2D &);

