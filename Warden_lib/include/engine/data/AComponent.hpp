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
#include <QJsonObject>

#include "include/engine/Event.hpp"

///
/// Component Abstract, used to generalize components
///
class AComponent
{
public:
    ///<Constructor, take a const string as parameter
    AComponent(const QString &name) : _name(name) {} ///<

    ///<Destructor
    virtual ~AComponent() = default; ///<

    ///<Call the update() of the component
    virtual void update(event) {} ///<

    ///<Return _name variable
    const QString &getName() {return _name;} ///<

    ///<Load a component from a .json object
    virtual void read(const QJsonObject &json) {(void)json;} ///<

    ///<Save a component in a .json object
    virtual void write(QJsonObject &json) const {(void)json;} ///<

protected:
    const QString _name;
};

#endif /* end of include guard: ACOMPONENT_HPP_ */
