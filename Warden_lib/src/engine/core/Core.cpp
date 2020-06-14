/*
** EPITECH PROJECT, 2019
** Core.cpp
** File description:
** Core Class Implementation
*/

#include "include/engine/core/Core.hpp"

Core::Core()
{

}

Core::~Core()
{

}

bool Core::update(const QSharedPointer<IScene> &scene, event event)
{
    if (!scene->update(event))
        return false;
    return true;
}

void Core::stop()
{

}
