/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalModuleError class declaration
*/

#ifndef GRAPHICALMODULEERROR_HPP
#define GRAPHICALMODULEERROR_HPP

#include <string>

#include "DisplayError.hpp"

/// @file /include/engine/error/GraphicalModuleError.hpp

namespace wd
{
    ///
    /// error namespace is used for Error class management
    ///
    namespace error
    {
        ///
        /// Display Error Class, Contain a message and a type of error
        ///
        class GraphicalModuleError : public wd::error::DisplayError {
            public:
                GraphicalModuleError(const std::string &message, const std::string &type = "Graphical Module") : DisplayError(message, type) {} ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
                ~GraphicalModuleError() = default;

                const std::string &getMsg() const {return _message;}                    ///<Return the error Message
                                                                                        ///<
                const std::string &getType() const {return _type;}                      ///<Return the error Type
                                                                                        ///<

            protected:
                std::string _message;
                std::string _type;
        };
    }
}

#endif /* !GRAPHICALMODULEERROR_HPP */
