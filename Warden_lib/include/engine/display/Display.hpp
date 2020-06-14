/*
** EPITECH PROJECT, 2019
** Display.hpp
** File description:
** Display Class Declaration
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

/// @file include/engine/display/Display.hpp

#include <QSharedPointer>

#include "include/engine/display/IGraphicalModule.hpp"
#include "include/engine/data/AGameObject.hpp"
#include "include/engine/display/IDisplay.hpp"

///
/// Display Class Declaration
///
class Display : public IDisplay
{
public:
    ///<Constructor
    Display(); ///<

    ///<Destructor
    ~Display(); ///<

    ///<Display every GameObject of a scene and get each input of the player
    void draw(const QSharedPointer<IScene> &, QQueue<event> &); ///<

    ///<Display only 1 GameObject
    void drawGameObject(const QSharedPointer<AGameObject>); ///<

    ///<PLay the sound of every objects
    void play(const QVector<QSharedPointer<SoundObject>> &); ///<

private:
    ///<Display every GameObject of a Layer of a Scene
    void drawLayer(const QVector<QSharedPointer<AGameObject>> &) const; ///<

    QSharedPointer<IGraphicalModule> _graphicalLib;
};

#endif /* end of include guard: DISPLAY_HPP_ */
