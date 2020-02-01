/*
** EPITECH PROJECT, 2019
** WardenEngine
** File description:
** Engine
*/

#include <SFML/System.hpp>
#include "Engine.hpp"

wd::Engine::Engine()
: _displayThread(_display.draw()), _coreThread(_core.Update())
{
    _network = nullptr;
    _ai = nullptr;
}

wd::Engine::~Engine()
{
    _displayThread.terminate();
    _coreThread.terminate();
}

void wd::Engine::Start() const
{
    _displayThread.launch();
    _coreThread.launch();
}

Void wd::Engine::Stop() const
{
    _displayThread.stop();
    _coreThread.stop();
}
