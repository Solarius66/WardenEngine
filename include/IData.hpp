/*
** EPITECH PROJECT, 2020
** IData
** File description:
** Definition of the Data Interface
*/

#pragma once

#include <string>
#include <exception>

#include "Data.hpp"

namespace wd
{
    class IData
    {
    public:
        IData() = delete;
        virtual ~IData();

        virtual void sceneSwap(const std::string &name) = 0;
        virtual void addScene(const wd::IScene &scene) = 0;
        virtual void removeScene(const std::string &name) = 0;
        virtual wd::IScene &getActiveScene() = 0;
    };
}
