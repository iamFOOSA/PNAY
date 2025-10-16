#ifndef LAB___4__CUBE_H
#define LAB___4__CUBE_H

#include "ThreeDShape.h"

class Cube : public ThreeDShape {
private:
    double side;

public:
    explicit Cube(double s);

    void print() const override;

    double area() const override;

    double volume() const override;

    void draw() const override;
};

#endif
