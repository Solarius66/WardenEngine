/*
** EPITECH PROJECT, 2019
** AComponent.hpp
** File description:
** Component Abstract Declaration
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

/// @file include/engine/data/AComponent.hpp

#include <QString>

#include "include/engine/Event.hpp"

///
/// Component Abstract, used to generalize components
///
class AComponent
{
public:
    AComponent(const QString &name) : _name(name) {}    ///<Constructor, take a const string as parameter
                                                        ///<
    virtual ~AComponent() = default;                    ///<Destructor
                                                        ///<

    virtual void update(event) {}           ///<Call the update() of the component
                                                ///<
    const QString &getName() {return _name;}    ///<Return _name variable
                                                ///<

protected:
    const QString _name;
};

#endif /* end of include guard: ACOMPONENT_HPP_ */
