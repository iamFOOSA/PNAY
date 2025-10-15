#include "../header /Cube.h"
#include <iostream>

Cube::Cube(double s) : side(s) {}

void Cube::print() const {
    std::cout << "Cube: side = " << side << std::endl;
}

double Cube::area() const {
    return 6 * side * side;
}

double Cube::volume() const {
    return side * side * side;
}

void Cube::draw() const {
    std::cout << std::endl;
    std::cout << "    +---------+" << std::endl;
    std::cout << "   /|        /|" << std::endl;
    std::cout << "  / |       / |" << std::endl;
    std::cout << " +---------+  |" << std::endl;
    std::cout << " |  |      |  |" << std::endl;
    std::cout << " |  +------|--+" << std::endl;
    std::cout << " | /       | /" << std::endl;
    std::cout << " +---------+" << std::endl;
    std::cout << "     Side: " << side << std::endl;
}