/*
** EPITECH PROJECT, 2019
** GameObjectError.hpp
** File description:
** GameObjectError Class Declaration
*/

#ifndef GAMEOBJECTERROR_HPP_
#define GAMEOBJECTERROR_HPP_

/// @file /include/engine/error/GameObjectError.hpp

#include "SceneManagerError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// GameObject Error Class, Contain a message and a type of error
        ///
        class GameObjectError : public wd::error::SceneManagerError
        {
        public:
            GameObjectError(const std::string &message, const std::string &type = "GameObject")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :SceneManagerError(message, type) {}                                              ///<
            ~GameObjectError() = default;                                                     ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: GAMEOBJECTERROR_HPP_ */
