/*
** EPITECH PROJECT, 2019
** SceneManager.cpp
** File description:
** SceneManager Class Implementation
*/

#include <iostream>
#include "SceneManager.hpp"

wd::SceneManager::SceneManager()
{
    _activeScene = "";
}

wd::SceneManager::~SceneManager()
{

}

void wd::SceneManager::sceneSwap(const std::string &name)
{
    if (_scenes.find(_activeScene) == _scenes.end())
        throw wd::error::SceneManagerError("Invalid Name of Scene '" + _activeScene + "' not found.");
    _scenes[_activeScene]->reset();
    _activeScene = name;
}

void wd::SceneManager::addScene(const std::shared_ptr<wd::IScene> &scene)
{
    _scenes[scene->getName()] = scene;
    _activeScene = scene->getName();
}

void wd::SceneManager::removeScene(const std::string &name)
{
    for (std::map<std::string, std::shared_ptr<wd::IScene>>::iterator it = _scenes.begin(); it != _scenes.end(); it++) {
        if (it->first == name)
            _scenes.erase(it);
    }
}

const std::shared_ptr<wd::IScene> &wd::SceneManager::getActiveScene()
{
    if (_scenes.find(_activeScene) == _scenes.end())
        throw wd::error::SceneManagerError("Invalid Name of Scene '" + _activeScene + "' not found.");
    return _scenes[_activeScene];
}

void wd::SceneManager::switchScene(int value)
{
    for (std::map<std::string, std::shared_ptr<wd::IScene>>::iterator it = _scenes.begin(); it != _scenes.end(); it++) {
        if (it->first == _activeScene) {
            if (value > 0) {
                if (std::next(it) == _scenes.end())
                    sceneSwap(_scenes.begin()->second->getName());
                else
                    sceneSwap(std::next(it)->second->getName());
            }
            if (value < 0) {
                if (it == _scenes.begin())
                    sceneSwap(std::prev(_scenes.end())->second->getName());
                else
                    sceneSwap(std::prev(it)->second->getName());
            }
        }
    }
}
