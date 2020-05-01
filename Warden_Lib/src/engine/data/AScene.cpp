/*
** EPITECH PROJECT, 2019
** AScene.cpp
** File description:
** AScene Class Implementation
*/

#include <iostream>

#include "AScene.hpp"
#include "SceneError.hpp"

wd::AScene::AScene(const std::string &name) : _name(name)
{
    _state = true;
}

wd::AScene::~AScene()
{
}

std::vector<std::shared_ptr<wd::AGameObject>> wd::AScene::getFromLayer(int layer)
{
    std::vector<std::shared_ptr<wd::AGameObject>> vector;

    for (std::size_t it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getLayer() == layer)
            vector.push_back(_objects[it]);
    }
    return vector;
}

std::vector<std::shared_ptr<wd::AGameObject>> wd::AScene::getFromID(int id)
{
    std::vector<std::shared_ptr<wd::AGameObject>> vector;

    for (std::size_t it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getID() == id)
            vector.push_back(_objects[it]);
    }
    return vector;
}

std::shared_ptr<wd::AGameObject> &wd::AScene::getFromName(const std::string &name)
{
    for (std::size_t it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getName() == name)
        return _objects[it];
    }
    throw wd::error::SceneError("Component Name '" + name + "' not found.");
}

const std::string & wd::AScene::getName() const
{
    return _name;
}

bool wd::AScene::update(wd::event event)
{
    try {
        for (std::size_t it = 0; it < _objects.size(); it++) {
            _objects[it]->update(event);
        }
    }
    catch (wd::SceneState &e) {
        _state = e.getState();
    }
    return _state;
}

void wd::AScene::addObject(const std::shared_ptr<wd::AGameObject> &object)
{
    _objects.push_back(object);
}

void wd::AScene::destroyGameObjectFromName(const std::string &name)
{
    for (std::vector<std::shared_ptr<wd::AGameObject>>::iterator it = _objects.begin(); it < _objects.end(); it++) {
        if ((*it)->getName() == name)
            _objects.erase(it);
    }
}

void wd::AScene::destroyGameObject()
{
    _objects.clear();
}

void wd::AScene::debug()
{
    std::cout << "Scene : " << _name << std::endl << "List of AGameObjects :" << std::endl;
    for (std::size_t x = 0; x < _objects.size(); x++) {
        std::cout << "\t" << _objects[x]->getName() << std::endl;
    }
}
