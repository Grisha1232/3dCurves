#pragma once
#include <cmath>
#include <string>
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
	Curve() {};
	virtual Point calculatePoint(double t) const {
		return {0, 0, 0};
	};
	virtual Point calculateDerivative(double t) const {
		return {0, 0, 0};
	};
	
	virtual void getCurve() const {
		std::cout << "Curve";
	}
	
	virtual double getRadius() const {
		return 0.0;
	};
	
	virtual std::string getName() const {
		return "Curve";
	}
};

class Circle: public Curve {
private:
	double radius;
public:
	Circle(double r) : radius(r) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
	
	void getCurve() const {
		std::cout << "Circle {radius = " + std::to_string(radius) + "}\n";
	}
	
	double getRadius() const {
		return radius;
	}
	std::string getName() const {
		return "Circle";
	}
};

class Ellipse: public Curve {
private:
	double radius1, radius2;
public:
	Ellipse(double r1, double r2): radius1(r1), radius2(r2) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
	
	void getCurve() const {
		std::cout << "Ellipse {r1 = " + std::to_string(radius1) +
		", r2 =" + std::to_string(radius2) +"}\n";
	}
	
	double getRadius() const {
		return radius1;
	}
	std::string getName() const {
		return "Ellipse";
	}
};

class Helix: public Curve {
private:
	double radius, step;
public:
	Helix(double r, double s): radius(r), step(s) {};
	Point calculatePoint(double t) const;
	Point calculateDerivative(double t) const;
	
	void getCurve() const {
		std::cout << "Helix {radius = " + std::to_string(radius) +
		"step = " + std::to_string(step) + "}\n";
	}
	
	double getRadius() const {
		return radius;
	}
	std::string getName() const {
		return "Helix";
	}
};