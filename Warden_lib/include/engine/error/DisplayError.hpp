/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** DisplayError class declaration
*/

#ifndef DISPLAYERROR_HPP
#define DISPLAYERROR_HPP

/// @file /include/engine/error/DisplayError.hpp

#include "warden_lib.h"

///
/// Display Error Class, Contain a message and a type of error
///
class DisplayError : public QException {
    public:
        DisplayError(const QString &message, const QString &type = "Display") : _message(message), _type(type) {} ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
        ~DisplayError() = default;

        const QString &getMsg() const {return _message;}                    ///<Return the error Message
                                                                                ///<
        const QString &getType() const {return _type;}                      ///<Return the error Type
                                                                                ///<

    protected:
        QString _message;
        QString _type;
};

#endif /* !DISPLAYERROR_HPP */
