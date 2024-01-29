#pragma once
#include <cmath>
#include <iostream>

struct Point {
	double x, y, z;
	
	friend std::ostream& operator <<(std::ostream& out, const Point& p) {
		out << "{" << p.x << ", " << p.y << ", " << p.z << "}";
		return out;
	}
};



class Curve {
public:
	virtual Point calculatePoint(double t) const;
	virtual Point calculateDerivative(double t) const;
};

class Circle: public Curve {
private:
	double radius;
public:
	Circle(double r) : radius(r) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
};

class Eclipse: public Curve {
private:
	double radius1, radius2;
public:
	Eclipse(double r1, double r2): radius1(r1), radius2(r2) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
};

class Helix: public Curve {
private:
	double radius, step;
public:
	Helix(double r, double s): radius(r), step(s) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
};