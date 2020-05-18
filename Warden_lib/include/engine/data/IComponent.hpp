/*
** EPITECH PROJECT, 2019
** IComponent.hpp
** File description:
** Component Interface Declaration
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

/// @file include/engine/data/IComponent.hpp

#include <string>

#include "warden_lib.h"

///
/// Component Interface, used to generalize components
///
class IComponent
{
public:
    IComponent();                       ///<Constructor
                                        ///<
    virtual ~IComponent() = default;    ///<Destructor
                                        ///<

    virtual void update(event) = 0;         ///<Call the update() of the component
                                                ///<
    virtual const QString &getName() = 0;       ///<Return Name Variable
                                                ///<
};

#endif /* end of include guard: ICOMPONENT_HPP_ */
