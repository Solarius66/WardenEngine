/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** ICore
*/

#pragma once

#include "IData.hpp"

namespace wd
{
    class ICore
    {
        public:
        ICore() = delete;
        virtual ~ICore();

        virtual void Update(wd::IScene &) = 0;
        virtual void Stop() = 0;
    };
}
