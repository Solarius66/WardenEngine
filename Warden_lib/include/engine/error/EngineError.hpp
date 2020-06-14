/*
** EPITECH PROJECT, 2019
** EngineError.hpp
** File description:
** EngineError Class Declaration
*/

#ifndef ENGINEERROR_HPP_
#define ENGINEERROR_HPP_

/// @file /include/engine/error/EngineError.hpp

#include <QException>

///
/// Engine Error Class, Contain a message and a type of error
///
class EngineError : public QException
{
public:
    ///<Constructor, take 2 strings as parameters, first used as error message, second used as error type
    EngineError(const QString &message, const QString &type = "Engine")
    { _message = message; _type = type;} ///<

     ///<Destructor
    ~EngineError() = default; ///<

    ///<Return the error Message
    const QString &getMsg() const {return _message;} ///<

    ///<Return the error Type
    const QString &getType() const {return _type;} ///<

protected:
    QString _message;
    QString _type;
};

#endif /* end of include guard: ENGINEERROR_HPP_ */
