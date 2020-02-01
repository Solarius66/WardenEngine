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
        throw std::invalid_argument("invalide name in sceneSwap");
    else
        this->_activeScene = name;
}

// add scene in map scene
void wd::Data::addScene(const wd::IScene &scene)
{
    if (scene == nullptr)
        throw std::invalid_argument("invalide scene in addScene");
    else
        this->_scene.insert(scene->getName(), scene);
}

// remove scene in map scene
void wd::Data::removeScene(const std::string &name)
{
    if (name.empty() == true || this->_scene.count(name) == 0)
        throw std::invalid_argument("invalide name in removeScene");
    else
        this->_scene.erase(name);
}
