/*
** EPITECH PROJECT, 2019
** TextBox.cpp
** File description:
** TextBox Class Implementation
*/

#include <chrono>
#include <ctime>

#include <iostream>
#include "TextBox.hpp"
#include "Transform.hpp"
#include "TextRenderer.hpp"

wd::TextBox::TextBox(const std::string &name, int id, int layer, const std::string &str) : AGameObject(name, id, layer)
{
    addComponent<wd::TextRenderer>("TextRenderer", str);
}

wd::TextBox::TextBox(wd::TextBox &entity) : AGameObject(entity.getName(), entity.getID(), entity.getLayer())
{
    _component = entity.getComponentList();
}
