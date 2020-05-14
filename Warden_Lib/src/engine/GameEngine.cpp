/*
** EPITECH PROJECT, 2019
** GameEngine.cpp
** File description:
** GameEngine Class Implementation
*/

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <functional>

#include <dirent.h>
#include <sys/types.h>

#include "GameEngine.hpp"
#include "Display.hpp"
#include "SceneManager.hpp"
#include "Core.hpp"
#include "EngineError.hpp"

wd::GameEngine::GameEngine()
{
    _displayModule = std::make_unique<wd::Display>();
    _dataModule = std::make_unique<wd::SceneManager>();
    _coreModule = std::make_unique<wd::Core>();
}

wd::GameEngine::~GameEngine()
{
}

void wd::GameEngine::loop()
{
    while (1) {
        _displayModule->draw(_dataModule->getActiveScene(), _events);
        if (_events.size() == 0)
            continue;
        if (_events.front() == wd::CLOSED_WINDOW)
            break;
        _coreModule->update(_dataModule->getActiveScene(), _events.front());
        _events.pop();
    }
}
