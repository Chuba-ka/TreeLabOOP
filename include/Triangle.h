#pragma once

#include "Figure.h"
#include <cmath>

class Triangle : public Figure
{
public:
    Triangle();
    Triangle(const Triangle &other);
    Triangle(double cx, double cy, double r);

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