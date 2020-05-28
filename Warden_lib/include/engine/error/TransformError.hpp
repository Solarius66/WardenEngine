/*
** EPITECH PROJECT, 2019
** TransformError.hpp
** File description:
** TransformError Class Declaration
*/

#ifndef TRANSFORMERROR_HPP_
#define TRANSFORMERROR_HPP_

/// @file /include/engine/error/TransformError.hpp

#include "warden_lib.h"

///
/// Transform Error Class, Contain a message and a type of error
///
class TransformError : public ComponentError
{
public:
    ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    TransformError(const QString &message, const QString &type = "Transform")
    :ComponentError(message, type) {} ///<

    ///<Destructor
    ~TransformError() = default; ///<
};

#endif /* end of include guard: TRANSFORMERROR_HPP_ */
