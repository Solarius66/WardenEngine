/*
** EPITECH PROJECT, 2019
** SceneManagerError.hpp
** File description:
** SceneManagerError Class Declaration
*/

#ifndef SCENEMANAGERERROR_HPP_
#define SCENEMANAGERERROR_HPP_

/// @file /include/engine/error/SceneManagerError.hpp

#include "EngineError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// SceneManager Error Class, Contain a message and a type of error
        ///
        class SceneManagerError : public wd::error::EngineError
        {
        public:
            SceneManagerError(const std::string &message, const std::string &type = "SceneManager")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :EngineError(message, type) {}                                              ///<
            ~SceneManagerError() = default;                                                     ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: SCENEMANAGERERROR_HPP_ */
