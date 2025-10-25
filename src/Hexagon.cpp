#include "Hexagon.h"

Hexagon::Hexagon() : center_x(0), center_y(0), radius(1)
{
    vertices.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        double angle = 2 * M_PI * i / 6;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Hexagon::Hexagon(const Hexagon &other)
    : Figure(other), center_x(other.center_x), center_y(other.center_y), radius(other.radius)
{
    vertices.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        double angle = 2 * M_PI * i / 6;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Hexagon::Hexagon(double cx, double cy, double r) : center_x(cx), center_y(cy), radius(r)
{
    vertices.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        double angle = 2 * M_PI * i / 6;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

std::pair<double, double> Hexagon::geometricCenter() const
{
    return {center_x, center_y};
}

double Hexagon::area() const
{
    return (3 * sqrt(3) / 2) * radius * radius;
}

Figure *Hexagon::clone() const
{
    return new Hexagon(*this);
}

bool Hexagon::equals(const Figure &other) const
{
    if (const Hexagon *otherHexagon = dynamic_cast<const Hexagon *>(&other))
    {
        return center_x == otherHexagon->center_x &&
               center_y == otherHexagon->center_y &&
               radius == otherHexagon->radius;
    }
    return false;
}

void Hexagon::print(std::ostream &os) const
{
    os << "Вершины шестиугольника:\n";
    for (const auto &v : vertices)
    {
        os << "(" << v.first << ", " << v.second << ")\n";
    }
}

void Hexagon::read(std::istream &is)
{
    std::cout << "Введите центр (x y) и радиус: ";
    is >> center_x >> center_y >> radius;
    vertices.resize(6);
    for (int i = 0; i < 6; ++i)
    {
        double angle = 2 * M_PI * i / 6;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}