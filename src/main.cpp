#include <iostream>
#include "lib/curve.h"
#include <memory>
#include <algorithm>
#include <random>
#include <vector>
#include <cmath>
#include <sstream>

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


std::shared_ptr<Curve> getCurve() {
	switch (Random::getIntNumber()) {
		case 1:
			return std::make_shared<Circle>(Random::getRealNumber());
		case 2:
			return std::make_shared<Ellipse>(Random::getRealNumber(), Random::getRealNumber());
		case 3:
			return std::make_shared<Helix>(Random::getRealNumber(), Random::getRealNumber());
		default:
			return std::make_shared<Curve>();
	}
}


int main(int argc, char *argv[]) {
	
	int numberOfCurves = 5;
	if (argc == 2) {
		std::istringstream ss(argv[1]);
		if (!(ss >> numberOfCurves)) {
			std::cerr << "Invalid argument: " << argv[1] << "\n";
			std::cerr << "Please provide with integer number or without arguments\n";
			return -1;
		}
	}
	if (numberOfCurves > 100) {
		numberOfCurves = 100;
	}
	std::cout << numberOfCurves << "\n";
	double t = M_PI_4;
	
	std::vector<std::shared_ptr<Curve>> curves;
	std::vector<std::shared_ptr<Circle>> circles;
	
	for (int i = 0; i < numberOfCurves; i++) {
		auto curve = getCurve();
		curves.push_back(curve);
		curves.back()->getCurve();
		
		if (curve->getName() == "Circle") {
			circles.push_back(std::dynamic_pointer_cast<Circle>(curve));
		}
	}
	std::cout << "\n\nAt point t = Pi/4\n";
	for (const auto &curve : curves) {
		curve->getCurve();
		std::cout << "at point t = " << t << " is " << curve->calculatePoint(t) << "\n";
		std::cout << "at point t = " << t << " Derivative is " << curve->calculateDerivative(t) << "\n";
		std::cout << "\n";
	}
	
	std::cout << "\nvector of circles is size of " << circles.size() << "\n";
	for (const auto &circle : circles) {
		circle->getCurve();
	}
	
	std::cout << "\n-----------\n";
	std::cout << "sorted circles:\n\n";
	
	std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle> &x, const std::shared_ptr<Circle> &y) {
		return x->getRadius() < y->getRadius();
	});
	
	double total_sum_radii = 0;
	
	for (const auto &circle : circles) {
		total_sum_radii += circle->getRadius();
		circle->getCurve();
	}
	std::cout << "total sum of radii = " << total_sum_radii << "\n";
	
	return 0;
}