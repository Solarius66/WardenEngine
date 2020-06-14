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

#include "include/engine/sound/SoundObject.hpp"
#include "include/engine/data/IScene.hpp"
#include "include/engine/data/AGameObject.hpp"

///
/// Display Interface Declaration
///
class IDisplay
{
public:
    ///<Constructor
    IDisplay() = default; ///<

    ///<Destructor
    virtual ~IDisplay() = default; ///<

    ///<Display every GameObject of a scene and get each input of the player
    virtual void draw(const QSharedPointer<IScene> &, QQueue<event> &) = 0; ///<

    ///<Display only 1 GameObject
    virtual void drawGameObject(const QSharedPointer<AGameObject>) = 0; ///<

    ///<PLay the sound of every objects
    virtual void play(const QVector<QSharedPointer<SoundObject>> &) = 0; ///<

protected:
    ///<Display every GameObject of a Layer of a Scene
    virtual void drawLayer(const QVector<QSharedPointer<AGameObject>> &) const = 0; ///<

};

#endif /* end of include guard: IDISPLAY_HPP_ */
