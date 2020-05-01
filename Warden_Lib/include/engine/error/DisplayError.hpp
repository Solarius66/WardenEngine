/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** DisplayError class declaration
*/

#ifndef DISPLAYERROR_HPP
#define DISPLAYERROR_HPP

#include <exception>
#include <string>

/// @file /include/engine/error/DisplayError.hpp

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
        class DisplayError : public std::exception {
            public:
                DisplayError(const std::string &message, const std::string &type = "Display") : _message(message), _type(type) {} ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
                ~DisplayError() = default;

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

#endif /* !DISPLAYERROR_HPP */
