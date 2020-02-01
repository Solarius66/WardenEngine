/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** Core
*/

#include "Core.hpp"

wd::Core::Core()
{
}

// update scene in core
void wd::CoreUpdate(wd::IScene &scene)
{
    scene->Update();
}

//
void wd::CoreStop()
{
}
