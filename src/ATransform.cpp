/*
** EPITECH PROJECT, 2020
** ATransform
** File description:
** ATransform abstract class member functions implementation
*/

#include "ATransform.hpp"

wd::ATransform::ATransform()
{
    _scale.x = 1;
    _scale.y = 1;
}

wd::ATransform::ATransform(const wd::ATransform &ref) : _position(ref._position), _scale(ref._scale), _rotation(ref._rotation)
{
}

wd::ATransform::~ATransform()
{
}

// Set _position from a wd::Vector2int passed as parameter

void wd::ATransform::setPosition(const wd::Vector2int &position)
{
    _position = position;
}

// Set _scale from a wd::Vector2int passed as parameter

void wd::ATransform::setScale(const wd::Vector2int &scale)
{
    _scale = scale;
}

// Set _size from a wd::Vector2int passed as parameter

void wd::ATransform::setSize(const wd::Vector2int &size)
{
    _size = size;
}

// Set _rotation from a float passed as parameter

void wd::ATransform::setRotation(const float &rotation)
{
    _rotation = rotation;
}

void wd::ATransform::Update()
{
}

// Overload on = operator to assign ref members to the current Transform

wd::ATransform &wd::ATransform::operator=(const wd::ATransform &ref)
{
    _position = ref._position;
    _scale = ref._scale;
    _rotation = ref._rotation;
    return *this;
}

// Overload << operator on std::cout to print Transform members : _position, _scale and _rotation

std::ostream &operator<<(std::ostream &os, const wd::ATransform &transform)
{
    return os << "Position: " << transform.getPosition() << std::endl << "Scale: " << transform.getScale() << std::endl << "Rotation: " << transform.getRotation();
}
