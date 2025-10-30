#pragma once

#include "Figure.h"
#include <cmath>

class Octagon : public Figure
{
public:
    Octagon();
    Octagon(const Octagon &other);
    Octagon(double cx, double cy, double r);

    std::pair<double, double> geometricCenter() const override;
    double area() const override;
    Figure *clone() const override;
    bool equals(const Figure &other) const override;

protected:
    void print(std::ostream &os) const override;
    void read(std::istream &is) override;

private:
    double center_x, center_y, radius;
};