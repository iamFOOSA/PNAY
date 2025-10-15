#include "../header /Square.h"
#include <iostream>

Square::Square(double s) : side(s) {}

void Square::print() const {
    std::cout << "Square: side = " << side << std::endl;
}

double Square::area() const {
    return side * side;
}

double Square::perimeter() const {
    return 4 * side;
}

void Square::draw() const {
    std::cout << "┌──────┐" << std::endl;
    std::cout << "│      │" << std::endl;
    std::cout << "│      │" << std::endl;
    std::cout << "└──────┘" << std::endl;
}