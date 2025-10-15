#ifndef LAB___4__SQUARE_H
#define LAB___4__SQUARE_H

#include "TwoDShape.h"

class Square : public TwoDShape {
private:
    double side;

public:
    Square(double s);

    void print() const override;

    double area() const override;

    double perimeter() const override;

    void draw() const override;
};

#endif
