/*
** EPITECH PROJECT, 2020
** AGameObject
** File description:
** AGameObject member functions implementation
*/

#include <string>
#include "AGameObject.hpp"
#include "ITransform.hpp"
#include "ICollider.hpp"
#include "ISprite.hpp"
#include "Enums.hpp"

wd::AGameObject::AGameObject(const std::string &name, const wd::ID &id) : _name(name), _id(id)
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

// Update GameObject each frame / TO-DO : define what will be called in this function

void wd::AGameObject::update()
{
}