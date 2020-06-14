/*
** EPITECH PROJECT, 2019
** GameObjectError.hpp
** File description:
** GameObjectError Class Declaration
*/

#ifndef GAMEOBJECTERROR_HPP_
#define GAMEOBJECTERROR_HPP_

/// @file /include/engine/error/GameObjectError.hpp

#include "include/engine/error/SceneManagerError.hpp"

///
/// GameObject Error Class, Contain a message and a type of error
///
class GameObjectError : public SceneManagerError
{
public:
    ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    GameObjectError(const QString &message, const QString &type = "GameObject")
    :SceneManagerError(message, type) {} ///<

    ///<Destructor
    ~GameObjectError() = default; ///<
};

#endif /* end of include guard: GAMEOBJECTERROR_HPP_ */
