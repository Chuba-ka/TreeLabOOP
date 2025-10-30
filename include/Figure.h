#pragma once

#include <vector>
#include <iostream>

class Figure
{
public:
    Figure() = default;
    Figure(const Figure &other);
    virtual ~Figure() = default;

    virtual std::pair<double, double> geometricCenter() const = 0;
    virtual double area() const = 0;

    virtual Figure *clone() const = 0;
    virtual bool equals(const Figure &other) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Figure &fig);
    friend std::istream &operator>>(std::istream &is, Figure &fig);

    Figure &operator=(const Figure &other);
    Figure &operator=(Figure &&other) noexcept;
    bool operator==(const Figure &other) const;

    explicit operator double() const { return area(); }

protected:
    virtual void print(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;

    std::vector<std::pair<double, double>> vertices;
};
