#include "../header /Triangle.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Triangle::Triangle(double b, double h, double s1, double s2)
        : base(b), height(h), side1(s1), side2(s2) {

    if (!isValidTriangle()) {
        throw std::invalid_argument("Invalid triangle: height doesn't match the sides");
    }
}

bool Triangle::isValidTriangle() const {
    if (base <= 0 || height <= 0 || side1 <= 0 || side2 <= 0) {
        return false;
    }

    if (side1 + side2 <= base || side1 + base <= side2 || side2 + base <= side1) {
        return false;
    }

    double s = (side1 + side2 + base) / 2;
    double areaHeron = sqrt(s * (s - side1) * (s - side2) * (s - base));

    double areaBaseHeight = (base * height) / 2;

    const double epsilon = 1e-6;
    return std::abs(areaHeron - areaBaseHeight) < epsilon;
}

void Triangle::print() const {
    std::cout << "Triangle: base = " << base << ", height = " << height
              << ", sides = " << side1 << ", " << side2 << std::endl;
}

double Triangle::area() const {
    return (base * height) / 2;
}

double Triangle::perimeter() const {
    return base + side1 + side2;
}

void Triangle::draw() const {
    std::cout << "    /\\    " << std::endl;
    std::cout << "   /  \\   " << std::endl;
    std::cout << "  /    \\  " << std::endl;
    std::cout << " /______\\ " << std::endl;
}