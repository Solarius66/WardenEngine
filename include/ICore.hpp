/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** ICore
*/

#ifndef ICORE_HPP_
#define ICORE_HPP_

#include "IScene.hpp"

namespace wd 
{
    class ICore 
    {
        public:
        ICore();
        virtual ~ICore() = 0;

        virtual void Update(wd::IScene activeScene) = 0;
        virtual void Stop() = 0;
    };
}

#endif /* !ICORE_HPP_ */
