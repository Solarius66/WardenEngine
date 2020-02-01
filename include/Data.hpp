/*
** EPITECH PROJECT, 2020
** Data
** File description:
** Definition of the Data Class
*/

#pragma once

#include <iostream>
#include <map>

#include "IData.hpp"
#include "IScene.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Data : public wd::IData
    {
    public:
        Data();
        ~Data() = default;

        void sceneSwap(const std::string &);
        void addScene(const wd::IScene &);
        void removeScene(const std::string &);
        wd::IScene &getActiveScene() {return this->_scene[this->_activeScene];};

    private:
        std::map<std::string, wd::IScene>   _scene;
        std::string                         _activeScene;
    };
}

#pragma pack(pop)
