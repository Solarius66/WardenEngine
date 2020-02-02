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

wd::ACollider::ACollider(const wd::Collider &ref) : _isCollide(ref._isCollide)
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

void wd::ACollider::onTriggerEnter()
{
}

void wd::ACollider::onTriggerExit()
{
}

void wd::ACollider::onTriggerStay()
{
}

// Update Collider member function

void wd::ACollider::Update(const std::vector<wd::IGameObject> &objects)
{
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
