/*
** EPITECH PROJECT, 2019
** WardenEngine
** File description:
** Mutex
*/

#pragma once

#include <mutex>

#include "IDisplay.hpp"
#include "IData.hpp"
#include "ICore.hpp"

#pragma pack(push, 1)

typedef struct mutex_s
{
    std::unique_ptr<wd::IDisplay>   _display;
    std::unique_ptr<wd::IData>      _data;
    std::unique_ptr<wd::ICore>      _core;
    std::mutex                      _mutex;
}   mutex_t;

#pragma pack(pop)
