/*
** EPITECH PROJECT, 2019
** SceneManager.cpp
** File description:
** SceneManager Class Implementation
*/

#include <QMapIterator>

#include "include/engine/data/SceneManager.hpp"

SceneManager::SceneManager()
{
    _activeScene = "";
}

SceneManager::~SceneManager()
{

}

void SceneManager::sceneSwap(const QString &name)
{
    if (_scenes.find(_activeScene) == _scenes.end())
        throw SceneManagerError("Invalid Name of Scene '" + _activeScene + "' not found.");
    _scenes[_activeScene]->reset();
    _activeScene = name;

}

void SceneManager::addScene(const QSharedPointer<IScene> &scene)
{
    _scenes[scene->getName()] = scene;
    _activeScene = scene->getName();
}

void SceneManager::removeScene(const QString &name)
{
    for (QMap<QString, QSharedPointer<IScene>>::iterator it = _scenes.begin(); it != _scenes.end(); it++) {
        if (it.key() == name)
            _scenes.erase(it);
    }
}

const QSharedPointer<IScene> &SceneManager::getActiveScene()
{
    if (_scenes.find(_activeScene) == _scenes.end())
        throw SceneManagerError("Invalid Name of Scene '" + _activeScene + "' not found.");
    return _scenes[_activeScene];
}
