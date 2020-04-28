/*
** EPITECH PROJECT, 2019
** MenuEntity.cpp
** File description:
** MenuEntity Class Implementation
*/

#include <chrono>
#include <ctime>

#include <iostream>
#include "MenuEntity.hpp"
#include "Transform.hpp"
#include "MoveMenuEntity.hpp"

wd::MenuEntity::MenuEntity(const std::string &name, int id, int layer, float speed) : AGameObject(name, id, layer)
{
    getComponent<wd::Transform>("Transform").setPosition(- (rand() % 10), rand() % 26, 0);
    addComponent<wd::MoveMenuEntity>("MoveMenuEntity", std::make_shared<wd::MenuEntity>(*this), speed);
}

wd::MenuEntity::MenuEntity(wd::MenuEntity &entity) : AGameObject(entity.getName(), entity.getID(), entity.getLayer())
{
    _component = entity.getComponentList();
}
