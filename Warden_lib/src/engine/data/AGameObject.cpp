/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GameObject Abstract class implementation
*/

#include <QString>
#include <QDebug>
#include <iostream>

#include "include/engine/data/AGameObject.hpp"
#include "include/engine/data/Transform.hpp"

AGameObject::AGameObject(const QString &name, int id, int layer) : _name(name), _id(id), _layer(layer)
{
    addComponent<Transform>("Transform");
}

AGameObject::AGameObject(AGameObject &obj) : _name(obj.getName()), _id(obj.getID()), _layer(obj.getLayer())
{
}

void AGameObject::debug()
{
    qDebug() << getName() << " :" << '\n';
    for (auto const& x : _component)
        qDebug() << x->getName() << '\n';
}

void AGameObject::update(event event)
{
    for (auto const& x : _component)
        x->update(event);
}