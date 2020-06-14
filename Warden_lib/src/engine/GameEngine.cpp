/*
** EPITECH PROJECT, 2019
** GameEngine.cpp
** File description:
** GameEngine Class Implementation
*/

#include <QQueue>

#include "include/engine/sound/Sound.hpp"
#include "include/engine/GameEngine.hpp"
#include "include/engine/display/Display.hpp"
#include "include/engine/data/SceneManager.hpp"
#include "include/engine/core/Core.hpp"

GameEngine::GameEngine()
{
    _displayModule = QSharedPointer<Display>(new Display);
    _dataModule = QSharedPointer<SceneManager>(new SceneManager);
    _coreModule = QSharedPointer<Core>(new Core);
    _soundModule = QSharedPointer<Sound>(new Sound);
}

GameEngine::~GameEngine()
{
}

void GameEngine::loop()
{
    while (1) {
        _displayModule->draw(_dataModule->getActiveScene(), _events);
        if (_events.size() == 0)
            continue;
        if (_events.front() == CLOSED_WINDOW)
            break;
        _coreModule->update(_dataModule->getActiveScene(), _events.front());
        _displayModule->play(_soundModule->getSound(_dataModule->getActiveScene()));
        _events.dequeue();
    }
}
