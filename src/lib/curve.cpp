#include "curve.h"

// Circle class definition

// x = r * cos(t)
// y = r * sin(t)
// z = 0 (because our circle is planar)
Point Circle::calculatePoint(double t) const {
	return {radius * std::cos(t), radius * std::sin(t), 0.0};
}
// derivative
// x = -r * sin(t)
// y = r * cos(t)
// z = 0
Point Circle::calculateDerivative(double t) const {
	return {-radius * std::sin(t), radius * std::cos(t), 0.0};
}


// Eclipse class definition

// x = r1 * cos(t)
// y = r2 * sin(t)
// z = 0 (because our eclipse is planar)
Point Eclipse::calculatePoint(double t) const {
	return {radius1 * std::cos(t), radius2 * std::sin(t), 0.0};
}
// derivative
// x = -r1 * sin(t)
// y = r2 * cos(t)
// z = 0
Point Eclipse::calculateDerivative(double t) const {
	return {-radius1 * std::sin(t), radius2 * std::cos(t), 0.0};

}

// Helix class definition

// x = r * cos(t)
// y = r * sin(t)
// z = step * t
Point Helix::calculatePoint(double t) const {
	return {radius * std::cos(t), radius * std:: sin(t), step * t};
}

// derivative

// x = -r * sin(t)
// y = r * cos(t)
// z = step
Point Helix::calculateDerivative(double t) const {
	return {-radius * std::sin(t), radius * std::cos(t), step};
}

