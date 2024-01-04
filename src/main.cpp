#include <iostream>
#include "lib/curve.h"
#include <algorithm>
#include <random>
#include <vector>
#include <cmath>

struct Random {
	Random() = delete;
	
	static double getRealNumber() {
		return u_double_f(random);
	}
	
	static int getIntNumber() {
		return u_int_f(random);
	}
	
private:
	static std::uniform_real_distribution<double> u_double_f;
	static std::uniform_int_distribution<int> u_int_f;
	static std::random_device random;
};
std::uniform_real_distribution<double> Random::u_double_f = std::uniform_real_distribution<double>(0.1, 100);
std::uniform_int_distribution<int> Random::u_int_f = std::uniform_int_distribution<int>(1, 3);
std::random_device Random::random;

Curve* getCurve() {
	switch (Random::getIntNumber()) {
		case 1:
			return new Circle(Random::getRealNumber());
		case 2:
			return new Ellipse(Random::getRealNumber(), Random::getRealNumber());
		case 3:
			return new Helix(Random::getRealNumber(), Random::getRealNumber());
		default:
			return new Curve();
	}
}


int main(int argc, char* argv[]) {
	int numberOfCurves = 20;
	double t = M_PI_4;

	std::vector<Curve*> curves;
	std::vector<Circle*> circles;
	
	for (int i = 0; i < numberOfCurves; i++) {
		curves.push_back(getCurve());
		curves.back()->getCurve();
	}
	
	std::cout << "\n\nAt point t = Pi/4\n";
	for (int i = 0; i < numberOfCurves; i++) {
		curves[i]->getCurve();
		std::cout << "at point t = " << t << " is " << curves[i]->calculatePoint(t) << "\n";
		std::cout << "at point t = " << t << " Derivative is " << curves[i]->calculateDerivative(t) << "\n";
		std::cout << "\n";
	}
	
	for (auto i : curves) {
		if (i->getName() == "Circle") {
			std::cout << i << "\n";
			i->getCurve();
			circles.push_back(reinterpret_cast<Circle*>(i));
		}
	}
	
	std::cout << "\nvector of circles is size of " << circles.size() << "\n";
	for (auto i : circles) {
		std::cout << i << "\n";
		i->getCurve();
	}
	
	std::cout << "\n-----------\n";
	std::cout << "sorted circles:\n\n";
	
	std::sort(circles.begin(), circles.end(), [](const Circle* x, const Circle* y) {
		return x->getRadius() < y->getRadius();
	});
	
	double total_sum_radii = 0;
	
	for (auto i : circles) {
		total_sum_radii += i->getRadius();
		i->getCurve();
	}
	std::cout << "total sum of radii = " << total_sum_radii << "\n";
	
	for (auto i: curves) {
		delete i;
	}
	
	return 0;
}