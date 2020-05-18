/*
** EPITECH PROJECT, 2019
** Core.hpp
** File description:
** Core Class Declaration
*/

#ifndef CORE_HPP_
#define CORE_HPP_

/// @file include/engine/core/Core.hpp

#include "include/engine/core/ICore.hpp"

///
/// Core Class, contain a queue of events
///
class Core : public ICore
{
public:
    Core();     ///<Constructor
                ///<
    ~Core();    ///<Destructor
                ///<

    bool update(const QSharedPointer<IScene> &, event);     ///<Call the Update() of the active Scene
                                                                    ///<
    void stop();                                                    ///<Stop the program loop
                                                                    ///<
};

#endif /* end of include guard: CORE_HPP_ */
