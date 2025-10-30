#include <cmath>
#include <iostream>

#include "Triangle.h"

Triangle::Triangle() : center_x(0), center_y(0), radius(1)
{
    vertices.resize(3);
    for (int i = 0; i < 3; ++i)
    {
        double angle = 2 * M_PI * i / 3;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Triangle::Triangle(const Triangle &other)
    : Figure(other), center_x(other.center_x), center_y(other.center_y), radius(other.radius)
{
    vertices.resize(3);
    for (int i = 0; i < 3; ++i)
    {
        double angle = 2 * M_PI * i / 3;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Triangle::Triangle(double cx, double cy, double r) : center_x(cx), center_y(cy), radius(r)
{
    vertices.resize(3);
    for (int i = 0; i < 3; ++i)
    {
        double angle = 2 * M_PI * i / 3;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

std::pair<double, double> Triangle::geometricCenter() const
{
    return {center_x, center_y};
}

double Triangle::area() const
{
    return (3 * sqrt(3) / 4) * radius * radius;
}

Figure *Triangle::clone() const
{
    return new Triangle(*this);
}

bool Triangle::equals(const Figure &other) const
{
    if (const Triangle *otherTriangle = dynamic_cast<const Triangle *>(&other))
    {
        return center_x == otherTriangle->center_x &&
               center_y == otherTriangle->center_y &&
               radius == otherTriangle->radius;
    }
    return false;
}

void Triangle::print(std::ostream &os) const
{
    os << "Вершины треугольника:\n";
    for (const auto &v : vertices)
    {
        os << "(" << v.first << ", " << v.second << ")\n";
    }
}

void Triangle::read(std::istream &is)
{
    std::cout << "Введите центр (x y) и радиус: ";
    is >> center_x >> center_y >> radius;
    vertices.resize(3);
    for (int i = 0; i < 3; ++i)
    {
        double angle = 2 * M_PI * i / 3;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}