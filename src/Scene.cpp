/*
** EPITECH PROJECT, 2019
** Scene.cpp
** File description:
** Scene member functions implementation
*/

#include "Scene.hpp"

wd::Scene::Scene(const std::string &name) : _name(name)
{

}

// return a vector of every IGameObject on layer taken as parameter
std::vector<IGameObject> wd::Scene::getFromLayer(wd::LAYER layer) const
{
    std::vector<IGameObject> tmp;

    for (int x = 0; x < _objects.size(); x++) {
        if _objects[x].getLayer() == layer)
            tmp.push_back(_objects[x]);
    }
    return tmp;
}

// return a vector of every IGameObject with ID taken as parameter
std::vector<IGameObject> wd::Scene::getFromID(wd::ID id) const
{
    std::vector<IGameObject> tmp;

    for (int x = 0; x < _objects.size(); x++) {
        if _objects[x].getID() == id)
            tmp.push_back(_objects[x]);
    }
    return tmp;
}

// return IGameObject with name taken as parameter
IGameObject &wd::Scene::getFromName(const std::string &name) const
{
    for (int x = 0; x < _objects.size(); x++)
        if (_objects[x].getName() == name)
            return _objects[x];
}

// Call each IGameObject Update() funtion member
void wd::Scene::Update()
{
    for (int x = 0; x < _objects.size(); x++)
        _objects[x].Update();
}

// add obj taken as parameter into IGameObject vector
IScene &wd::Scene::operator+(const IGameObject &obj)
{
    _objects.push_back(obj);
    return this;
}

// destroy IGameObject from _objects which name is equal to string taken as parameter
void wd::Scene::destroyIGameObjectFromName(const std::string &name)
{
    int x = 0;

    for (; x < _objects.size(); x++) {
        if (_objects[x].getName() == name)
            _objects.erase(x);
    }
}

// Display name of every IGameObject stored in _objects
void operator<<(std::ostream &s, const IScene &scene)
{
    for (int x = 0; x < _objects.size(); x++)
        s << _objects[x].getName();
    return s;
}
