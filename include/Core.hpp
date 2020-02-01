/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** Core
*/

#pragma once

#include <Event.hpp>

#include "ICore.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Core : public wd::ICore
    {
        public:
            Core();
            ~Core() = default;

            void Update(wd::IScene &);
            void Stop();

        private:
            sf::Event _event;
    };
}

#pragma pack(pop)
