#include <stdexcept>

#include "Array.h"

Array::Array(size_t initial_capacity) : capacity_(initial_capacity), size_(0)
{
    data = new Figure *[capacity_];
    for (size_t i = 0; i < capacity_; ++i)
    {
        data[i] = nullptr;
    }
}

Array::~Array()
{
    for (size_t i = 0; i < size_; ++i)
    {
        delete data[i];
    }
    delete[] data;
}

void Array::add(Figure *figure)
{
    if (size_ >= capacity_)
    {
        resize();
    }
    data[size_++] = figure;
}

void Array::remove(size_t index)
{
    if (index >= size_)
    {
        throw std::out_of_range("Неверный индекс");
    }
    delete data[index];
    for (size_t i = index; i < size_ - 1; ++i)
    {
        data[i] = data[i + 1];
    }
    data[--size_] = nullptr;
}

Figure *Array::get(size_t index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Неверный индекс");
    }
    return data[index];
}

size_t Array::size() const
{
    return size_;
}

double Array::totalArea() const
{
    double total = 0.0;
    for (size_t i = 0; i < size_; ++i)
    {
        total += static_cast<double>(*data[i]);
    }
    return total;
}

void Array::resize()
{
    size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
    Figure **new_data = new Figure *[new_capacity];
    for (size_t i = 0; i < new_capacity; ++i)
    {
        new_data[i] = nullptr;
    }
    for (size_t i = 0; i < size_; ++i)
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity_ = new_capacity;
}