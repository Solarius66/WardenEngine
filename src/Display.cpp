/*
** EPITECH PROJECT, 2019
** Display.cpp
** File description:
** Display member functions implementation
*/


#include "Display.hpp"

wd::Display::Display() : _window()
{

}

// display each layer of a scene taken as parameter
void wd::Display::draw(const wd::IScene &scene)
{
    for (wd::LAYER layer = wd::LAYER::BACKGROUND; layer >= wd::LAYER::HUD; --layer)
        drawLayer(scene.getFromLayer(layer));
}

// display an GameObjects taken as parameter
void wd::Display::drawGameObject(const std::shared_ptr<wd::IGameObject> &obj)
{
    _window->draw(obj);
}

// display GameObjects of a layer taken as parameter
void wd::Display::drawLayer(const std::vector<std::shared_ptr<wd::IGameObject>> &vector)
{
    for (unsigned int x = 0; x < vector.size(); x++)
        if (vector[x]->getSprite()->getIsActive() == 1)
            drawGameObject(vector[x]);
}
