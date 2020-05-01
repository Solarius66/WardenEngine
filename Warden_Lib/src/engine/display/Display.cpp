/*
** EPITECH PROJECT, 2019
** Display.cpp
** File description:
** Display Class Implementation
*/

#include <dlfcn.h>
#include <iostream>

#include "Display.hpp"
#include "Macros.hpp"
#include "EngineError.hpp"
#include "SFMLModule.hpp"

wd::Display::Display()
{
    _graphicalLib = std::make_unique<wd::SFMLModule>();
}

wd::Display::~Display()
{

}

void wd::Display::draw(const std::shared_ptr<wd::IScene> &scene, std::queue<wd::event> &eventList)
{
    _graphicalLib->manageEvent(eventList);
    for (int x = BACKGROUND; x <= HUD; x++) {
        drawLayer(scene->getFromLayer(x));
    }
}

void wd::Display::drawGameObject(const std::shared_ptr<wd::AGameObject> gameObject)
{
    _graphicalLib->draw(gameObject);
}

void wd::Display::drawLayer(const std::vector<std::shared_ptr<wd::AGameObject>> &gameObjectList) const
{
    for (unsigned int x = 0; x < gameObjectList.size(); x++) {
        _graphicalLib->draw(gameObjectList[x]);
    }
}
