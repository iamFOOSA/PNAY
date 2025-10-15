#ifndef LAB___4__TRIANGLE_H
#define LAB___4__TRIANGLE_H

#include "TwoDShape.h"

class Triangle : public TwoDShape {
private:
    double base;
    double height;
    double side1, side2;

public:
    Triangle(double b, double h, double s1, double s2);

    void print() const override;

    double area() const override;

    double perimeter() const override;

    void draw() const override;

private:
    bool isValidTriangle() const;
};

#endif
