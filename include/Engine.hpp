/*
** EPITECH PROJECT, 2019
** Engine.hpp
** File description:
** Engine class
*/

#pragma once

#include <iostream>
#include <memory>

#include "IEngine.hpp"
#include "IDisplay.hpp"
#include "ICore.hpp"
#include "IData.hpp"
#include "IScene.hpp"
#include "Mutex.hpp"
// #include "INetwork.hpp"
// #include "IArtificialIntelligence.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Engine : public wd::IEngine
    {
        public:
            Engine();
            ~Engine();

            // Member functions
            void Start();
            void displayLoop() final;
            void coreLoop() final;

        private:
            std::unique_ptr<wd::ICore>                      _core;
            mutex_t                                         _mutex;
            // std::unique_ptr<wd::INetwork>                   _network = nullptr;
            // std::unique_ptr<wd::IArtificialIntelligence>    _ai = nullptr;
    };
}

#pragma pack(pop)
