/*
** EPITECH PROJECT, 2019
** MeshRendererError.hpp
** File description:
** MeshRendererError Class Declaration
*/

#ifndef MESHRENDERERERROR_HPP_
#define MESHRENDERERERROR_HPP_

/// @file /include/engine/error/MeshRendererError.hpp

#include "warden_lib.h"

///
/// MeshRenderer Error Class, Contain a message and a type of error
///
class MeshRendererError : public ComponentError
{
public:
    MeshRendererError(const QString &message, const QString &type = "MeshRenderer")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    :ComponentError(message, type) {}                                              ///<
    ~MeshRendererError() = default;                                                     ///<Destructor
                                                                                ///<
};
#endif /* end of include guard: MESHRENDERERERROR_HPP_ */
