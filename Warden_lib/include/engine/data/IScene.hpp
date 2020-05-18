/*
** EPITECH PROJECT, 2019
** IScene.hpp
** File description:
** Scene Interface Declaration
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

/// @file include/engine/data/IScene.hpp

#include <QSharedPointer>
#include <QVector>

#include "include/engine/data/AGameObject.hpp"

///
/// Scene Interface Implementation
///
class IScene
{
public:
    IScene() = default;             ///<Constructor
                                    ///<
    virtual ~IScene() = default;    ///<Destructor
                                    ///<

    virtual QVector<QSharedPointer<AGameObject>>   getFromLayer(int) = 0;                      ///<Return a vector containing all AGameObjects from a Layer specified as parameter
                                                                                                        ///<
    virtual QVector<QSharedPointer<AGameObject>>   getFromID(int) = 0;                         ///<Return a vector containing all AGameObjects from an ID specified as parameter
                                                                                                        ///<
    virtual QVector<QSharedPointer<AGameObject>>   getObjects() = 0;                           ///<Return the vector of AGameObject
                                                                                                        ///<
    virtual QSharedPointer<AGameObject> &              getFromName(const QString &) = 0;       ///<Return a Shared_ptr pointing to a AGameObject which name is specified as parameter
                                                                                                        ///<
    virtual const QString &                             getName() const = 0;                        ///<Return the name of the Scene
                                                                                                        ///<
    virtual int                                             getScore() = 0;                             ///<Return the Score of the Scene
                                                                                                        ///<
    virtual void                                            setScore(int) = 0;                          ///<Return the Score of the Scene
                                                                                                        ///<

    virtual bool    update(event) = 0;                                      ///<Call update() of every AGameObject contained in the IScene
                                                                                ///<
    virtual void    addObject(const QSharedPointer<AGameObject> &) = 0;    ///<Add a AGameObject to the vector of the Scene
                                                                                ///<
    virtual void    destroyGameObjectFromName(const QString &) = 0;         ///<Remove a AGameObject from the vector, which name is specified as parameter
                                                                                ///<
    virtual void    destroyGameObject() = 0;                                    ///<Remove all AGameObject from the vector
                                                                                ///<
    virtual void    reset() = 0;                                                ///<Reset the scene as made in the constructor
                                                                                ///<

    virtual void debug() = 0;                                                   ///<Display Name of every AGameObject contained in the Scene (Used for debugging)
                                                                                ///<
};

#endif /* end of include guard: ISCENE_HPP_ */
