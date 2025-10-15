#ifndef LAB___4__CYLINDER_H
#define LAB___4__CYLINDER_H

#include "ThreeDShape.h"

class Cylinder : public ThreeDShape {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h);

    void print() const override;

    double area() const override;

    double volume() const override;

    void draw() const override;
};

#endif
