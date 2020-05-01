/*
** EPITECH PROJECT, 2019
** TransformError.hpp
** File description:
** TransformError Class Declaration
*/

#ifndef TRANSFORMERROR_HPP_
#define TRANSFORMERROR_HPP_

/// @file /include/engine/error/TransformError.hpp

#include "ComponentError.hpp"

namespace wd
{
    namespace error
    {
        ///
        /// Transform Error Class, Contain a message and a type of error
        ///
        class TransformError : public wd::error::ComponentError
        {
        public:
            TransformError(const std::string &message, const std::string &type = "Transform")     ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            :ComponentError(message, type) {}                                              ///<
            ~TransformError() = default;                                                     ///<Destructor
                                                                                        ///<
        };
    }
}

#endif /* end of include guard: TRANSFORMERROR_HPP_ */
