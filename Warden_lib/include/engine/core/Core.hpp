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
    ///<Constructor
    Core(); ///<

    ///<Destructor
    ~Core(); ///<

    ///<Call the Update() of the active Scene
    bool update(const QSharedPointer<IScene> &, event); ///<

    ///<Stop the program loop
    void stop(); ///<

};

#endif /* end of include guard: CORE_HPP_ */
