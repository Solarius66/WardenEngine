/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GraphicalModuleError class declaration
*/

#ifndef GRAPHICALMODULEERROR_HPP
#define GRAPHICALMODULEERROR_HPP

/// @file /include/engine/error/GraphicalModuleError.hpp

#include "warden_lib.h"

///
/// Display Error Class, Contain a message and a type of error
///
class GraphicalModuleError : public DisplayError {
    public:
        GraphicalModuleError(const QString &message, const QString &type = "Graphical Module") : DisplayError(message, type) {} ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
        ~GraphicalModuleError() = default;

        const QString &getMsg() const {return _message;}                    ///<Return the error Message
                                                                                ///<
        const QString &getType() const {return _type;}                      ///<Return the error Type
                                                                                ///<

    protected:
        QString _message;
        QString _type;
};

#endif /* !GRAPHICALMODULEERROR_HPP */
