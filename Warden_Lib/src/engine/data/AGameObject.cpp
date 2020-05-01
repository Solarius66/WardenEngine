/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GameObject Abstract class implementation
*/

#include <memory>
#include <iostream>

#include "IComponent.hpp"
#include "AGameObject.hpp"
#include "GameObjectError.hpp"
#include "Transform.hpp"

wd::AGameObject::AGameObject(const std::string &name, int id, int layer) : _name(name), _id(id), _layer(layer)
{
    addComponent<wd::Transform>("Transform");
}

wd::AGameObject::AGameObject(wd::AGameObject &obj) : _name(obj.getName()), _id(obj.getID()), _layer(obj.getLayer())
{
}

void wd::AGameObject::debug()
{
    std::cout << getName() << " :" << '\n';
    for (auto const& x : _component)
        std::cout << x.second->getName() << '\n';
}

void wd::AGameObject::update(wd::event event)
{
    for (auto const& x : _component)
        x.second->update(event);
}
