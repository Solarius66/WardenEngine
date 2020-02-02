/*
** EPITECH PROJECT, 2019
** IEngine.hpp
** File description:
** IEngine class
*/

#pragma once

#include "Engine.hpp"

namespace wd
{
    class IEngine
    {
        public:
            IEngine();
            virtual ~IEngine();

            virtual void Start() = 0;
            virtual void displayLoop() = 0;
            virtual void coreLoop() = 0;
    };
}
