#pragma once

#include "Figure.h"

class Array
{
public:
    Array(size_t initial_capacity = 10);
    ~Array();

    void add(Figure *figure);
    void remove(size_t index);
    Figure *get(size_t index) const;
    size_t size() const;
    double totalArea() const;

private:
    Figure **data;
    size_t capacity_;
    size_t size_;
    void resize();
};
