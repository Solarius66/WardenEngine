/*
** EPITECH PROJECT, 2019
** SceneError.hpp
** File description:
** SceneError Class Declaration
*/

#ifndef SCENEERROR_HPP_
#define SCENEERROR_HPP_

/// @file /include/engine/error/SceneError.hpp

#include "SceneManagerError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// Scene Error Class, Contain a message and a type of error
        ///
        class SceneError : public wd::error::SceneManagerError
        {
        public:
            SceneError(const std::string &message, const std::string &type = "Scene")   ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :SceneManagerError(message, type) {}                                              ///<
            ~SceneError() = default;                                                    ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: SCENEERROR_HPP_ */
