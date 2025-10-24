#include "Octagon.h"

Octagon::Octagon() : center_x(0), center_y(0), radius(1)
{
    vertices.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        double angle = 2 * M_PI * i / 8;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Octagon::Octagon(const Octagon &other)
    : Figure(other), center_x(other.center_x), center_y(other.center_y), radius(other.radius)
{
    vertices.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        double angle = 2 * M_PI * i / 8;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

Octagon::Octagon(double cx, double cy, double r) : center_x(cx), center_y(cy), radius(r)
{
    vertices.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        double angle = 2 * M_PI * i / 8;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}

std::pair<double, double> Octagon::geometricCenter() const
{
    return {center_x, center_y};
}

double Octagon::area() const
{
    return 2 * (1 + sqrt(2)) * radius * radius;
}

Figure *Octagon::clone() const
{
    return new Octagon(*this);
}

bool Octagon::equals(const Figure &other) const
{
    if (const Octagon *otherOctagon = dynamic_cast<const Octagon *>(&other))
    {
        return center_x == otherOctagon->center_x &&
               center_y == otherOctagon->center_y &&
               radius == otherOctagon->radius;
    }
    return false;
}

void Octagon::print(std::ostream &os) const
{
    os << "Вершины восьмиугольника:\n";
    for (const auto &v : vertices)
    {
        os << "(" << v.first << ", " << v.second << ")\n";
    }
}

void Octagon::read(std::istream &is)
{
    std::cout << "Введите центр (x y) и радиус: ";
    is >> center_x >> center_y >> radius;
    vertices.resize(8);
    for (int i = 0; i < 8; ++i)
    {
        double angle = 2 * M_PI * i / 8;
        vertices[i] = {center_x + radius * cos(angle), center_y + radius * sin(angle)};
    }
}