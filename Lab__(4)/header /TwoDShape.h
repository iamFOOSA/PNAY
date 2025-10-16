#ifndef LAB___4__TWODSHAPE_H
#define LAB___4__TWODSHAPE_H

#include "Shape .h"

class TwoDShape : public Shape {
public:
    ~TwoDShape() override = default;

    virtual double perimeter() const = 0;

    double volume() const override { return 0; }
};

#endif
