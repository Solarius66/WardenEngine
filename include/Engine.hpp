/*
** EPITECH PROJECT, 2019
** Engine.hpp
** File description:
** Engine class
*/

#pragma once

#include <iostream>
#include <memory>
#include <SFML/System.hpp>

#include "IEngine.hpp"
#include "IDisplay.hpp"
#include "ICore.hpp"
#include "IData.hpp"
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
            void Start() const;
            void Stop() const;

        private:
            std::unique_ptr<wd::IDisplay>                   _display;
            std::unique_ptr<wd::ICore>                      _core;
            std::unique_ptr<wd::IData>                      _data;
            // std::unique_ptr<wd::INetwork>                   _network = nullptr;
            // std::unique_ptr<wd::IArtificialIntelligence>    _ai = nullptr;
            sf::Mutex                                       _mutex;
            sf::Thread                                      _displayThread;
            sf::Thread                                      _coreThread;
    };
}

#pragma pack(pop)
