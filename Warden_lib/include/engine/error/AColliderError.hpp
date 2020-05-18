/*
** EPITECH PROJECT, 2019
** AColliderError.hpp
** File description:
** AColliderError Class Declaration
*/

#ifndef ACOLLIDERERROR_HPP_
#define ACOLLIDERERROR_HPP_

/// @file /include/engine/error/AColliderError.hpp

#include <QString>

#include "include/engine/error/ComponentError.hpp"

///
/// ACollider Error Class, Contain a message and a type of error
///
class AColliderError : public ComponentError
{
public:
    AColliderError(const QString &message, const QString &type = "ACollider")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    :ComponentError(message, type) {}                                              ///<
    ~AColliderError() = default;                                                     ///<Destructor
                                                                                ///<
};

#endif /* end of include guard: ACOLLIDERERROR_HPP_ */
