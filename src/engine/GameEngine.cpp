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
#include "IGameModule.hpp"
#include "MenuScene.hpp"

wd::GameEngine::GameEngine()
{
    _displayModule = std::make_unique<wd::Display>();
    _dataModule = std::make_unique<wd::SceneManager>();
    _coreModule = std::make_unique<wd::Core>();
    _dataModule->addScene(std::make_shared<wd::MenuScene>());
    _dataModule->sceneSwap("Menu");
}

wd::GameEngine::~GameEngine()
{
}

void wd::GameEngine::loop()
{
    while (1) {
        _displayModule->draw(_dataModule->getActiveScene(), _events);
        if ((!_coreModule->update(_dataModule->getActiveScene(), _events.front()) && _dataModule->getActiveScene()->getName() != "Menu")
        || (_events.front() == wd::TAB && _dataModule->getActiveScene()->getName() != "Menu")) {
            int score = _dataModule->getActiveScene()->getScore();
            _dataModule->sceneSwap("Menu");
            _dataModule->getActiveScene()->setScore(score);
        }
        if (_events.size() == 0)
            continue;
        if (_events.front() == wd::CLOSED_WINDOW)
            break;
        _events.pop();
    }
}
