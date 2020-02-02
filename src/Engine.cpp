/*
** EPITECH PROJECT, 2019
** WardenEngine
** File description:
** Engine
*/

#include <functional>
#include <thread>

#include "Engine.hpp"
#include "IScene.hpp"

wd::Engine::Engine()
{
    // _network = nullptr;
    // _ai = nullptr;
}

wd::Engine::~Engine()
{}

void wd::Engine::Start()
{
    std::thread displayThread(&wd::Engine::displayLoop, this);
    std::thread coreThread(&wd::Engine::coreLoop, this);

    displayThread.join();
    coreThread.join();
}

void wd::Engine::displayLoop()
{
    while (1) {
        if (_mutex._mutex.try_lock()) {
            _mutex._mutex.lock();
            _mutex._display->draw(_mutex._data->getActiveScene());
            _mutex._mutex.unlock();
        }
    }
}

void wd::Engine::coreLoop()
{
    while (1) {
        if (_mutex._mutex.try_lock()) {
            _mutex._mutex.lock();
            _mutex._core->Update(_mutex._data->getActiveScene());
            _mutex._mutex.unlock();
        }
    }
}
