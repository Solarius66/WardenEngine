/*
** EPITECH PROJECT, 2019
** Window.cpp
** File description:
** Window member functions implementation
*/

#include "Window.hpp"

wd::Window::Window(const std::string &title, int x, int y)
: _mode(x, y), _title(title), _window(_mode, _title)
{

}

// set _window framerate to the framerate taken as parameter
void wd::Window::setFrameRate(unsigned int frameRate)
{
    _frameRate = frameRate;
    _window.setFrameRateLimit(frameRate);
}

// draw the sprite contained in the IGameObject taken as parameter
void wd::Window::draw(const wd::IGameObject &obj) const
{
    _window.draw(obj.getSprite().getSprite());
}
