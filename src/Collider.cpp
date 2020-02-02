/*
** EPITECH PROJECT, 2020
** Collider
** File description:
** Collider member functions implementation
*/

#include <iostream>
#include <ostream>
#include "Collider.hpp"

wd::Collider::Collider()
{
}

wd::Collider::Collider(const wd::Collider &ref) : _isCollide(ref._isCollide)
{
}

wd::Collider::Collider::~Collider()
{
}

// Set _isCollide from a bool passed as parameter

void wd::Collider::setIsCollide(const bool &isCollide)
{
    _isCollide = isCollide;
}

// Trigger collider member functions

void wd::Collider::onTriggerEnter()
{
}

void wd::Collider::onTriggerExit()
{
}

void wd::Collider::onTriggerStay()
{
}

// Update Collider member function

void wd::Collider::Update(const std::vector<wd::IGameObject> &objects)
{
}

// Overload on = operator to assign ref members to the current Collider

wd::Collider &wd::Collider::operator=(const wd::Collider &ref)
{
    _isCollide = ref._isCollide;
    return *this;
}

// Overload << operator on std::cout to print _isCollide in alpha format of Collider

std::ostream &operator<<(std::ostream &os, const wd::Collider &collider)
{
    return os << "isCollide: " << std::boolalpha << collider.getIsCollide();
}
