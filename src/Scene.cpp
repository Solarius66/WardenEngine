/*
** EPITECH PROJECT, 2019
** Scene.cpp
** File description:
** Scene member functions implementation
*/

#include "Scene.hpp"
#include "AGameObject.hpp"

wd::Scene::Scene(const std::string &name) : _name(name)
{

}

// return a vector of every IGameObject on layer taken as parameter
std::vector<std::shared_ptr<wd::IGameObject>> wd::Scene::getFromLayer(wd::LAYER layer) const
{
    std::vector<std::shared_ptr<wd::IGameObject>> tmp;

    for (unsigned int x = 0; x < _objects.size(); x++) {
        if (_objects[x]->getLayer() == layer)
            tmp.push_back(_objects[x]);
    }
    return tmp;
}

// return a vector of every IGameObject with ID taken as parameter
std::vector<std::shared_ptr<wd::IGameObject>> wd::Scene::getFromID(wd::ID id) const
{
    std::vector<std::shared_ptr<wd::IGameObject>> tmp;

    for (unsigned int x = 0; x < _objects.size(); x++) {
        if (_objects[x]->getID() == id)
            tmp.push_back(_objects[x]);
    }
    return tmp;
}

// return IGameObject with name taken as parameter
const std::shared_ptr<wd::IGameObject> &wd::Scene::getFromName(const std::string &name) const
{
    for (unsigned int x = 0; x < _objects.size(); x++)
        if (_objects[x]->getName() == name)
            return _objects[x];
    throw std::exception();
}

// Call each IGameObject Update() funtion member
void wd::Scene::Update()
{
    for (unsigned int x = 0; x < _objects.size(); x++)
        _objects[x]->Update(_objects);
}

// add obj taken as parameter into IGameObject vector
wd::IScene &wd::Scene::operator+(const std::shared_ptr<wd::IGameObject> &obj)
{
    _objects.push_back(obj);
    return *this;
}

// destroy IGameObject from _objects which name is equal to string taken as parameter
void wd::Scene::destroyIGameObjectFromName(const std::string &name)
{
    unsigned int x = 0;

    for (; x < _objects.size(); x++) {
        if (_objects[x]->getName() == name)
            _objects.erase(_objects.begin() + x);
    }
}

// Display name of every IGameObject stored in _objects
std::ostream &operator<<(std::ostream &s, const wd::IScene &scene)
{
    for (unsigned int x = 0; x < scene.getObjects().size(); x++)
        s << scene.getObjects()[x]->getName();
    return s;
}
