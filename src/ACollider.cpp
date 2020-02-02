/*
** EPITECH PROJECT, 2020
** ACollider
** File description:
** ACollider abstract class member functions implementation
*/

#include <iostream>
#include <ostream>

#include "ACollider.hpp"

wd::ACollider::ACollider()
{
}

wd::ACollider::ACollider(const wd::ACollider &ref) : _isCollide(ref._isCollide)
{
}

wd::ACollider::~ACollider()
{
}

// Set _isCollide from a bool passed as parameter

void wd::ACollider::setIsCollide(const bool &isCollide)
{
    _isCollide = isCollide;
}

// Trigger collider member functions

void wd::ACollider::onTriggerEnter(std::shared_ptr<wd::IGameObject> other, wd::IGameObject *obj)
{
    static_cast<void>(other);
    static_cast<void>(obj);
}

void wd::ACollider::onTriggerExit(std::shared_ptr<wd::IGameObject> other, wd::IGameObject *obj)
{
    static_cast<void>(other);
    static_cast<void>(obj);
}

void wd::ACollider::onTriggerStay(std::shared_ptr<wd::IGameObject> other, wd::IGameObject *obj)
{
    static_cast<void>(other);
    static_cast<void>(obj);
}

// Update Collider member function

void wd::ACollider::Update(const std::vector<std::shared_ptr<wd::IGameObject>> &objects, wd::IGameObject *obj)
{
    for (auto &p : objects) {
        if (obj->getName() == p->getName())
            continue;
        if ((obj->getTransform()->getPosition().x <= p->getTransform()->getPosition().x + p->getTransform()->getSize().x)
        && (obj->getTransform()->getPosition().y <= p->getTransform()->getPosition().y + p->getTransform()->getSize().y)
        && (obj->getTransform()->getPosition().x + obj->getTransform()->getSize().x >= p->getTransform()->getPosition().x)
        && (obj->getTransform()->getPosition().y + obj->getTransform()->getSize().y >= p->getTransform()->getPosition().y)) {
            this->onTriggerEnter(p, obj);
        }
    }
}

// Overload on = operator to assign ref members to the current Collider

wd::ACollider &wd::ACollider::operator=(const wd::ACollider &ref)
{
    _isCollide = ref._isCollide;
    return *this;
}

// Overload << operator on std::cout to print _isCollide in alpha format of Collider

std::ostream &operator<<(std::ostream &os, const wd::ACollider &collider)
{
    return os << "isCollide: " << std::boolalpha << collider.getIsCollide();
}
