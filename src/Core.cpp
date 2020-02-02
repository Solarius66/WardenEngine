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
void wd::Core::Update(wd::IScene &scene)
{
    scene.Update();
}

//
void wd::Core::Stop()
{
}
