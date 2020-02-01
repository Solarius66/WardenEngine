/*
** EPITECH PROJECT, 2020
** AGameObject
** File description:
** AGameObject member functions implementation
*/

#include <iostream>
#include <ostream>
#include <string>
#include "AGameObject.hpp"
#include "ITransform.hpp"
#include "ICollider.hpp"
#include "ISprite.hpp"
#include "Enums.hpp"

wd::AGameObject::AGameObject(const std::string &name, const wd::ID &id) : _name(name), _id(id)
{
}

wd::AGameObject::AGameObject(const wd::AGameObject &ref) : _id(ref._id), _name(ref._name), _layer(ref._layer), _transform(ref._transform), _collider(ref._collider), _sprite(ref.sprite)
{
}

wd::AGameObject::~AGameObject()
{
}

// Set _layer from LAYER enum passed as parameter

void wd::AGameObject::setLayer(const wd::LAYER &layer)
{
    _layer = layer;
}

// Set _transform from an ITransform passed as parameter

void wd::AGameObject::setTransform(const wd::ITransform &transform)
{
    _transform = transform;
}

// Set _collider from an ICollider passed as parameter

void wd::AGameObject::setCollider(const wd::ICollider &collider)
{
    _collider = collider;
}

// Set _sprite from and Isprite passed as parameter

void wd::AGameObject::setSprite(const wd::ISprite &sprite)
{
    _sprite = sprite;
}

// Update GameObject each frame

void wd::AGameObject::update()
{
    // TO-DO : define what will be called in this function
}

// Overload on = operator to assign ref members to the current AGameObject

wd::AGameObject &wd::AGameObject::operator=(const wd::AGameObject &ref)
{
    _layer = ref._layer;
    _transform = ref._transform;
    _collider = ref._collider;
    _sprite = ref._sprite;
    return *this;
}

// Overload << operator on std::cout to print GameObject _name

std:ostream &operator<<(std::ostream &os, const wd::AGameObject &object)
{
    return os << object.getName() << std::endl;
}