/*
** EPITECH PROJECT, 2020
** Data
** File description:
** Data member functions implementation
*/

#include <stdexcept>

#include "Data.hpp"

wd::Data::Data()
{

}

// change current scene
void wd::Data::sceneSwap(const std::string &name)
{
    if (name.empty() == true || this->_scene.count(name) == 0)
        throw std::invalid_argument("invalid name in sceneSwap");
    else
        this->_activeScene = name;
}

// add scene in map scene
void wd::Data::addScene(wd::IScene &scene)
{
    _scene[scene.getName()] = &scene;
    // _scene[scene.getName()] = std::make_shared<wd::IScene>(&scene);
}

// remove scene in map scene
void wd::Data::removeScene(const std::string &name)
{
    if (name.empty() == true || this->_scene.count(name) == 0)
        throw std::invalid_argument("invalid name in removeScene");
    else
        this->_scene.erase(name);
}
