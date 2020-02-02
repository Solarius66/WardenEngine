/*
** EPITECH PROJECT, 2020
** AGameObject
** File description:
** AGameObject member functions implementation
*/

#include <ostream>
#include <string>
#include "AGameObject.hpp"
#include "ITransform.hpp"
#include "ICollider.hpp"
#include "ISprite.hpp"
#include "Enums.hpp"

wd::AGameObject::AGameObject(const std::string &name, const wd::ID &id) : _name(name)
{
    _id = id;
    _transform = nullptr;
}

wd::AGameObject::AGameObject(const wd::AGameObject &ref) : _name(ref._name), _id(ref._id), _layer(ref._layer), _transform(ref._transform), _collider(ref._collider), _sprite(ref._sprite)
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

void wd::AGameObject::setTransform(std::shared_ptr<wd::ITransform> transform)
{
    _transform = transform;
}

// Set _collider from an ICollider passed as parameter

void wd::AGameObject::setCollider(std::shared_ptr<wd::ICollider> collider)
{
    _collider = collider;
}

// Set _sprite from and Isprite passed as parameter

void wd::AGameObject::setSprite(std::shared_ptr<wd::ISprite> sprite)
{
    _sprite = sprite;
}

// Update GameObject each frame

void wd::AGameObject::Update(const std::vector<wd::IGameObject > & objects)
{
    _transform.Update();
    _collider.Update(objects);
    _sprite.Update(_transform);
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

std::ostream &operator<<(std::ostream &os, const wd::AGameObject &object)
{
    return os << object.getName();
}
