/*
** EPITECH PROJECT, 2019
** IGameModule.hpp
** File description:
** GameModule Interface Declaration
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

/// @file include/engine/IGameModule.hpp

#include "IScene.hpp"

namespace wd
{
    class IGameModule
    {
    public:
        IGameModule() = default;            ///<Constructor
                                            ///<
        virtual ~IGameModule() = default;   ///<Destructor
                                            ///<

        virtual std::shared_ptr<wd::IScene> getScene() const = 0; ///<Return Created scene of the game
                                                                        ///<
    };
}

#endif /* end of include guard: IGAMEMODULE_HPP_ */
