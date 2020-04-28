/*
** EPITECH PROJECT, 2019
** EngineError.hpp
** File description:
** EngineError Class Declaration
*/

#ifndef ENGINEERROR_HPP_
#define ENGINEERROR_HPP_

#include <exception>

/// @file /include/engine/error/EngineError.hpp

namespace wd
{
    ///
    /// error namespace is used for Error class management
    ///
    namespace error
    {
        ///
        /// Engine Error Class, Contain a message and a type of error
        ///
        class EngineError : public std::exception
        {
        public:
            ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
            EngineError(const std::string &message, const std::string &type = "Engine")
            { _message = message; _type = type;}                                        ///<
            ~EngineError() = default;                                                   ///<Destructor
                                                                                        ///<

            const std::string &getMsg() const {return _message;}                        ///<Return the error Message
                                                                                        ///<
            const std::string &getType() const {return _type;}                          ///<Return the error Type
                                                                                        ///<

        protected:
            std::string _message;
            std::string _type;
        };
    }
}

#endif /* end of include guard: ENGINEERROR_HPP_ */
