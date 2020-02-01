/*
** EPITECH PROJECT, 2020
** Transform
** File description:
** Transform member functions implementation
*/

#include "Transform.hpp"

wd::Transform::Transform()
{
}

wd::Transform::Transform(const wd::Transform &ref) : _position(ref._position), _scale(ref._scale), _rotation(ref._rotation)
{
}

wd::Transform::~Transform()
{
}

// Set _position from a wd::Vector2 passed as parameter

void wd::Transform::setPosition(const wd::Vector2 &position)
{
    _position = position;
}

// Set _scale from a wd::Vector2 passed as parameter

void wd::Transform::setScale(const wd::Vector2 &scale)
{
    _scale = scale;
}

// Set _rotation from a float passed as parameter

float wd::Transform::setRotation(const float &rotation)
{
    _rotation = rotation;
}

void wd::Transform::update()
{
}

// Overload on = operator to assign ref members to the current Transform

wd::Transform &wd::Transform::operator=(const wd::Transform &ref)
{
    _position = ref._position;
    _scale = ref._scale;
    _rotation = ref._rotation;
}

// Overload << operator on std::cout to print Transform members : _position, _scale and _rotation

std::ostream &operator<<(std::ostream &os, const wd::Transform &transform)
{
    return os << "Position: " << transform.getPosition() << std::endl << "Scale: " << transform.getScale() << std::endl << "Rotation: " << transform.getRotation();
}