/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core Class Implementation
*/

#include "Core.hpp"

wd::Core::Core()
{

}

wd::Core::~Core()
{

}

bool wd::Core::update(const std::shared_ptr<wd::IScene> &scene, wd::event event)
{
    if (!scene->update(event))
        return false;
    return true;
}

void wd::Core::stop()
{

}
