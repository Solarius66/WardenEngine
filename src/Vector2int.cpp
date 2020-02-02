/*
** EPITECH PROJECT, 2020
** Vector2
** File description:
** Vector2 member functions immplementation
*/

#include "Vector2int.hpp"

wd::Vector2int::Vector2int(const int &xRef, const int &yRef) : x(xRef), y(yRef)
{
}

wd::Vector2int::Vector2int(const Vector2int &ref) : x(ref.x), y(ref.y)
{
}

wd::Vector2int::~Vector2int()
{
}

wd::Vector2int &wd::Vector2int::operator=(const Vector2int &ref)
{
    x = ref.x;
    y = ref.y;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const wd::Vector2int &vector)
{
    return os << "x:" << vector.x << " y:" << vector.y;
}
