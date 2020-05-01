/*
** EPITECH PROJECT, 2019
** ICore.hpp
** File description:
** COre Interface Declaration
*/

#ifndef ICORE_HPP_
#define ICORE_HPP_

/// @file include/engine/core/ICore.hpp

#include "IScene.hpp"
#include "Event.hpp"

namespace wd
{
    ///
    /// Core Interface Implementation
    ///
    class ICore
    {
    public:
        ICore() = default;              ///<Constructor
                                        ///<
        virtual ~ICore() = default;     ///<Destructor
                                        ///<

        virtual bool update(const std::shared_ptr<wd::IScene> &, wd::event) = 0;    ///<Call the Update() of the active Scene
                                                                            ///<
        virtual void stop() = 0;                                            ///<Stop the program loop
                                                                            ///<
    };
}

#endif /* end of include guard: ICORE_HPP_ */
