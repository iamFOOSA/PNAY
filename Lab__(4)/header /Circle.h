#ifndef LAB___4__CIRCLE_H
#define LAB___4__CIRCLE_H

#include <iostream>
#include "Const.h"
#include "TwoDShape.h"

class Circle : public TwoDShape {
private:
    double radius;
public:
    Circle(double r);

    void print() const override;

    double area() const override;

    double perimeter() const override;

    void draw() const override;
};

#endif
