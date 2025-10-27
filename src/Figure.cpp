#include <iostream>
#include <vector>

#include "Figure.h"

Figure::Figure(const Figure &other) : vertices(other.vertices) {}

std::ostream &operator<<(std::ostream &os, const Figure &fig)
{
    fig.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Figure &fig)
{
    fig.read(is);
    return is;
}

Figure &Figure::operator=(const Figure &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Figure &Figure::operator=(Figure &&other) noexcept
{
    if (this != &other)
    {
        vertices = std::move(other.vertices);
        other.vertices.clear();
    }
    return *this;
}

bool Figure::operator==(const Figure &other) const
{
    return equals(other);
}