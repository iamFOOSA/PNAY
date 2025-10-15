#include "../header /Circle.h"
#include "../header /Const.h"
#include <iostream>

Circle::Circle(double r) : radius(r) {}

void Circle::print() const {
    std::cout << "Circle: radius = " << radius << std::endl;
}

double Circle::area() const {
    return constants::P * radius * radius;
}

double Circle::perimeter() const {
    return 2 * constants::P * radius;
}

void Circle::draw() const {
    std::cout << "   ***   " << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "*       *" << std::endl;
    std::cout << " *     * " << std::endl;
    std::cout << "   ***   " << std::endl;
}