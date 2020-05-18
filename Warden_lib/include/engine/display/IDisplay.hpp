/*
** EPITECH PROJECT, 2019
** IDisplay.hpp
** File description:
** Display Interface Declaration
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

/// @file include/engine/display/IDisplay.hpp

#include <QSharedPointer>
#include <QQueue>

#include "include/engine/data/IScene.hpp"
#include "include/engine/data/AGameObject.hpp"

///
/// Display Interface Declaration
///
class IDisplay
{
public:
    IDisplay() = default;               ///<Constructor
                                        ///<
    virtual ~IDisplay() = default;      ///<Destructor
                                        ///<

    virtual void draw(const QSharedPointer<IScene> &, QQueue<event> &) = 0;        ///<Display every GameObject of a scene and get each input of the player
                                                                                            ///<
    virtual void drawGameObject(const QSharedPointer<AGameObject>) = 0;                ///<Display only 1 GameObject
                                                                                            ///<

protected:
    virtual void drawLayer(const QVector<QSharedPointer<AGameObject>> &) const = 0;    ///<Display every GameObject of a Layer of a Scene
                                                                                                ///<
};

#endif /* end of include guard: IDISPLAY_HPP_ */
