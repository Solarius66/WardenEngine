/*
** EPITECH PROJECT, 2019
** ComponentError.hpp
** File description:
** ComponentError Class Declaration
*/

#ifndef COMPONENTERROR_HPP_
#define COMPONENTERROR_HPP_

/// @file /include/engine/error/ComponentError.hpp

#include "SceneManagerError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// Component Error Class, Contain a message and a type of error
        ///
        class ComponentError : public wd::error::SceneManagerError
        {
        public:
            ComponentError(const std::string &message, const std::string &type = "Component")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :SceneManagerError(message, type) {}                                              ///<
            ~ComponentError() = default;                                                     ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: COMPONENTERROR_HPP_ */
