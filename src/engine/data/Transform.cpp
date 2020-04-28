/*
** EPITECH PROJECT, 20.01.09
** Transform.cpp
** File description:
** Transform Class Implementation
*/
#include <iostream>
#include "Transform.hpp"

wd::Transform::Transform(wd::Vector3float position) : AComponent("Transform")
{
    _position = position;
    _rotation = {0.0, 0.0, 0.0};
    _scale = {1.0, 1.0, 1.0};
    _size = {1, 1, 1};
}

wd::Transform::Transform(float x, float y, float z) : AComponent("Transform")
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _rotation = {0.0, 0.0, 0.0};
    _scale = {1.0, 1.0, 1.0};
    _size = {1, 1, 1};
}

wd::Transform::~Transform()
{

}

void wd::Transform::translate(wd::Vector3float pos)
{
    _position.x += pos.x;
    _position.y += pos.y;
    _position.z += pos.z;
}

void wd::Transform::translate(float x, float y, float z)
{
    _position.x += x;
    _position.y += y;
    _position.z += z;
}

void wd::Transform::rotate(wd::Vector3float rotation)
{
    _rotation.x += rotation.x;
    _rotation.y += rotation.y;
    _rotation.z += rotation.z;
}

void wd::Transform::rotate(float x, float y, float z)
{
    _rotation.x += x;
    _rotation.y += y;
    _rotation.z += z;
}

void wd::Transform::rescale(wd::Vector3float scale)
{
    _scale.x += scale.x;
    _scale.y += scale.y;
    _scale.z += scale.z;
}

void wd::Transform::rescale(float x, float y, float z)
{
    _scale.x += x;
    _scale.y += y;
    _scale.z += z;
}

void wd::Transform::resize(wd::Vector3float size)
{
    _size.x += size.x;
    _size.y += size.y;
    _size.z += size.z;
}

void wd::Transform::resize(float x, float y, float z)
{
    _size.x += x;
    _size.y += y;
    _size.z += z;
}

void wd::Transform::setPosition(wd::Vector3float position)
{
    _position.x = position.x;
    _position.y = position.y;
    _position.z = position.z;
}

void wd::Transform::setPosition(float x, float y, float z)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

void wd::Transform::setRotation(wd::Vector3float position)
{
    _rotation.x = position.x;
    _rotation.y = position.y;
    _rotation.z = position.z;
}

void wd::Transform::setRotation(float x, float y, float z)
{
    _rotation.x = x;
    _rotation.y = y;
    _rotation.z = z;
}

void wd::Transform::setScale(wd::Vector3float position)
{
    _scale.x = position.x;
    _scale.y = position.y;
    _scale.z = position.z;
}

void wd::Transform::setScale(float x, float y, float z)
{
    _scale.x = x;
    _scale.y = y;
    _scale.z = z;
}

void wd::Transform::setSize(wd::Vector3float position)
{
    _size.x = position.x;
    _size.y = position.y;
    _size.z = position.z;
}

void wd::Transform::setSize(float x, float y, float z)
{
    _size.x = x;
    _size.y = y;
    _size.z = z;
}

void wd::Transform::update(wd::event event)
{
    static_cast<void>(event);
}
