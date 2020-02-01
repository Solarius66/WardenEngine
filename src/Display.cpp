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
    for (wd::LAYER layer = wd::BACKGROUND; layer >= wd::HUD; layer--)
        drawLayer(scene.getFromLayer());
}

// display an GameObjects taken as parameter
void wd::Display::drawGameObject(const wd::IGameObject &obj)
{
    _window.draw(obj);
}

// display GameObjects of a layer taken as parameter
void wd::Display::drawLayer(std::vector<wd::IGameObject> &vector)
{
    for (int x = 0; vector[x]; x++)
        drawGameObject(vector[x]);
}
