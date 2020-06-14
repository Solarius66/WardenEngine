/*
** EPITECH PROJECT, 2019
** Display.cpp
** File description:
** Display Class Implementation
*/

#include "include/engine/display/Display.hpp"
#include "include/engine/display/SFMLModule.hpp"
#include "include/engine/Macros.hpp"

Display::Display()
{
    _graphicalLib = QSharedPointer<SFMLModule>(new SFMLModule);
}

Display::~Display()
{

}

void Display::draw(const QSharedPointer<IScene> &scene, QQueue<event> &eventList)
{
    _graphicalLib->manageEvent(eventList);
    for (int x = BACKGROUND; x <= HUD; x++) {
        drawLayer(scene->getFromLayer(x));
    }
}

void Display::drawGameObject(const QSharedPointer<AGameObject> gameObject)
{
    _graphicalLib->draw(gameObject);
}

void Display::drawLayer(const QVector<QSharedPointer<AGameObject>> &gameObjectList) const
{
    for (int x = 0; x < gameObjectList.size(); x++) {
        _graphicalLib->draw(gameObjectList[x]);
    }
}
