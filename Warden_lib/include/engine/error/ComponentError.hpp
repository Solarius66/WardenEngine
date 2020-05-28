/*
** EPITECH PROJECT, 2019
** ComponentError.hpp
** File description:
** ComponentError Class Declaration
*/

#ifndef COMPONENTERROR_HPP_
#define COMPONENTERROR_HPP_

/// @file /include/engine/error/ComponentError.hpp

#include <QString>

#include "include/engine/error/SceneManagerError.hpp"

///
/// Component Error Class, Contain a message and a type of error
///
class ComponentError : public SceneManagerError
{
public:
    ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    ComponentError(const QString &message, const QString &type = "Component")
    :SceneManagerError(message, type) {} ///<

    ///<Destructor
    ~ComponentError() = default; ///<
};

#endif /* end of include guard: COMPONENTERROR_HPP_ */
