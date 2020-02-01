/*
** EPITECH PROJECT, 2019
** IEngine.hpp
** File description:
** IEngine class
*/

#pragma once

namespace wd
{
    class IEngine
    {
        public:
            IEngine() = delete;
            virtual ~IEngine();

            virtual void Start() const = 0;
            virtual void Stop() const = 0;
    };
}
