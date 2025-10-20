#include "../header /Sphere.h"
#include "../header /Const.h"
#include <iostream>

Sphere::Sphere(double r) : radius(r) {}

void Sphere::print() const {
    std::cout << "Sphere: radius = " << radius << std::endl;
}

double Sphere::area() const {
    return 4 * constants::pi * radius * radius;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * constants::pi * radius * radius * radius;
}

void Sphere::draw() const {
    std::cout << "    *****    " << std::endl;
    std::cout << "  *       *  " << std::endl;
    std::cout << " *         * " << std::endl;
    std::cout << " *         * " << std::endl;
    std::cout << "  *       *  " << std::endl;
    std::cout << "    *****    " << std::endl;
}
