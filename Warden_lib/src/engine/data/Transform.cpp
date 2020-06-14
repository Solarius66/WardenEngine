/*
** EPITECH PROJECT, 20.01.09
** Transform.cpp
** File description:
** Transform Class Implementation
*/
#include <iostream>

#include "include/engine/data/Transform.hpp"

Transform::Transform(Vector3float position) : AComponent("Transform")
{
    _position = position;
    _rotation = {0.0, 0.0, 0.0};
    _scale = {1.0, 1.0, 1.0};
    _size = {1, 1, 1};
}

Transform::Transform(float x, float y, float z) : AComponent("Transform")
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _rotation = {0.0, 0.0, 0.0};
    _scale = {1.0, 1.0, 1.0};
    _size = {1, 1, 1};
}

Transform::~Transform()
{

}

void Transform::translate(Vector3float pos)
{
    _position.x += pos.x;
    _position.y += pos.y;
    _position.z += pos.z;
}

void Transform::translate(float x, float y, float z)
{
    _position.x += x;
    _position.y += y;
    _position.z += z;
}

void Transform::rotate(Vector3float rotation)
{
    _rotation.x += rotation.x;
    _rotation.y += rotation.y;
    _rotation.z += rotation.z;
}

void Transform::rotate(float x, float y, float z)
{
    _rotation.x += x;
    _rotation.y += y;
    _rotation.z += z;
}

void Transform::rescale(Vector3float scale)
{
    _scale.x += scale.x;
    _scale.y += scale.y;
    _scale.z += scale.z;
}

void Transform::rescale(float x, float y, float z)
{
    _scale.x += x;
    _scale.y += y;
    _scale.z += z;
}

void Transform::resize(Vector3float size)
{
    _size.x += size.x;
    _size.y += size.y;
    _size.z += size.z;
}

void Transform::resize(float x, float y, float z)
{
    _size.x += x;
    _size.y += y;
    _size.z += z;
}

void Transform::setPosition(Vector3float position)
{
    _position.x = position.x;
    _position.y = position.y;
    _position.z = position.z;
}

void Transform::setPosition(float x, float y, float z)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

void Transform::setRotation(Vector3float position)
{
    _rotation.x = position.x;
    _rotation.y = position.y;
    _rotation.z = position.z;
}

void Transform::setRotation(float x, float y, float z)
{
    _rotation.x = x;
    _rotation.y = y;
    _rotation.z = z;
}

void Transform::setScale(Vector3float position)
{
    _scale.x = position.x;
    _scale.y = position.y;
    _scale.z = position.z;
}

void Transform::setScale(float x, float y, float z)
{
    _scale.x = x;
    _scale.y = y;
    _scale.z = z;
}

void Transform::setSize(Vector3float position)
{
    _size.x = position.x;
    _size.y = position.y;
    _size.z = position.z;
}

void Transform::setSize(float x, float y, float z)
{
    _size.x = x;
    _size.y = y;
    _size.z = z;
}

void Transform::read(const QJsonObject &json)
{

}

void Transform::write(QJsonObject &json) const
{
    json["name"] = _name;
    json["position_x"] = _position.x;
    json["position_y"] = _position.y;
    json["position_z"] = _position.z;
    json["rotation_x"] = _rotation.x;
    json["rotation_y"] = _rotation.y;
    json["rotation_z"] = _rotation.z;
    json["scale_x"] = _scale.x;
    json["scale_y"] = _scale.y;
    json["scale_z"] = _scale.z;
    json["size_x"] = _size.x;
    json["size_y"] = _size.y;
    json["size_z"] = _size.z;
}

void Transform::update(event event)
{
    static_cast<void>(event);
}
