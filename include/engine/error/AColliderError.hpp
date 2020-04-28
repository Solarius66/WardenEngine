/*
** EPITECH PROJECT, 2019
** AColliderError.hpp
** File description:
** AColliderError Class Declaration
*/

#ifndef ACOLLIDERERROR_HPP_
#define ACOLLIDERERROR_HPP_

/// @file /include/engine/error/AColliderError.hpp

#include "ComponentError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// ACollider Error Class, Contain a message and a type of error
        ///
        class AColliderError : public wd::error::ComponentError
        {
        public:
            AColliderError(const std::string &message, const std::string &type = "ACollider")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :ComponentError(message, type) {}                                              ///<
            ~AColliderError() = default;                                                     ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: ACOLLIDERERROR_HPP_ */
