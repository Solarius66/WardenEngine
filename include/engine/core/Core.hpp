/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core Class Declaration
*/

#ifndef CORE_HPP_
#define CORE_HPP_

/// @file include/engine/core/Core.hpp

#include "ICore.hpp"
#include "Event.hpp"

namespace wd
{
    ///
    /// Core Class, contain a queue of events
    ///
    class Core : public wd::ICore
    {
    public:
        Core();     ///<Constructor
                    ///<
        ~Core();    ///<Destructor
                    ///<

        bool update(const std::shared_ptr<wd::IScene> &, wd::event);    ///<Call the Update() of the active Scene
                                                                ///<
        void stop();                                            ///<Stop the program loop
                                                                ///<
    };
}

#endif /* end of include guard: CORE_HPP_ */
