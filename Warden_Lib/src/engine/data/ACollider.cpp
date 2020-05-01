/*
** EPITECH PROJECT, 2019
** ACollider.cpp
** File description:
** ACollider Class Implementation
*/

#include <iostream>

#include "ACollider.hpp"
#include "Transform.hpp"

wd::ACollider::ACollider(std::shared_ptr<wd::AGameObject> thisGameObject, const std::shared_ptr<wd::IScene> &scene)
: AComponent("ACollider")
{
    _this = thisGameObject;
    _scene = scene;
}

wd::ACollider::~ACollider()
{

}

void wd::ACollider::update(wd::event _event)
{
    static_cast<void>(_event);
    for (unsigned int x = 0; x < _scene->getObjects().size(); x++) {
        if (_this->getName() == _scene->getObjects()[x]->getName())
            continue;
        if ((_this->getComponent<wd::Transform>("Transform").getPosition().x + _this->getComponent<wd::Transform>("Transform").getSize().x) >
        (_scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getPosition().x) &&
        (_this->getComponent<wd::Transform>("Transform").getPosition().y + _this->getComponent<wd::Transform>("Transform").getSize().y) >
        (_scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getPosition().y) &&
        (_scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getPosition().x + _scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getSize().x) >
        (_this->getComponent<wd::Transform>("Transform").getPosition().x) &&
        (_scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getPosition().y + _scene->getObjects()[x]->getComponent<wd::Transform>("Transform").getSize().y) >
        (_this->getComponent<wd::Transform>("Transform").getPosition().y)) {
            _isCollide[_scene->getObjects()[x]->getName()] = false;
            if (_isCollide[_scene->getObjects()[x]->getName()] == false) {
                onTriggerEnter(_scene->getObjects()[x]);
                _isCollide[_scene->getObjects()[x]->getName()] = true;
            }
            if (_isCollide[_scene->getObjects()[x]->getName()] == true)
                onTriggerStay(_scene->getObjects()[x]);
        } else if (_isCollide[_scene->getObjects()[x]->getName()] == true) {
            onTriggerExit(_scene->getObjects()[x]);
            _isCollide.erase(_scene->getObjects()[x]->getName());
        }
    }
}

void wd::ACollider::onTriggerEnter(std::shared_ptr<wd::AGameObject> other)
{
    std::cout << "Trigger Enter with " << other->getName() << std::endl;
}

void wd::ACollider::onTriggerStay(std::shared_ptr<wd::AGameObject> other)
{
    std::cout << "Trigger Stay with " << other->getName() << std::endl;
}

void wd::ACollider::onTriggerExit(std::shared_ptr<wd::AGameObject> other)
{
    std::cout << "Trigger Exit with " << other->getName() << std::endl;
}
