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
        ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
        GraphicalModuleError(const QString &message, const QString &type = "Graphical Module") : DisplayError(message, type) {} ///<

        ///<Destructor
        ~GraphicalModuleError() = default; ///<

        ///<Return the error Message
        const QString &getMsg() const {return _message;} ///<

        ///<Return the error Type
        const QString &getType() const {return _type;} ///<

    protected:
        QString _message;
        QString _type;
};

#endif /* !GRAPHICALMODULEERROR_HPP */
