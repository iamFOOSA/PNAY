#include "../header /Cylinder.h"
#include "../header /Const.h"
#include <iostream>

Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}

void Cylinder::print() const {
    std::cout << "Cylinder: radius = " << radius << ", height = " << height << std::endl;
}

double Cylinder::area() const {
    return 2 * constants::P * radius * (radius + height);
}

double Cylinder::volume() const {
    return constants::P * radius * radius * height;
}

void Cylinder::draw() const {
    std::cout << "   _____   " << std::endl;
    std::cout << "  /     \\  " << std::endl;
    std::cout << " /       \\ " << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << "|         |" << std::endl;
    std::cout << " \\       / " << std::endl;
    std::cout << "  \\_____/  " << std::endl;
}