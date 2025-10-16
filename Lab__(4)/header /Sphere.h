#ifndef LAB___4__SPHERE_H
#define LAB___4__SPHERE_H

#include "ThreeDShape.h"

class Sphere : public ThreeDShape {
private:
    double radius;

public:
    explicit Sphere(double r);

    void print() const override;

    double area() const override;

    double volume() const override;

    void draw() const override;
};

#endif
