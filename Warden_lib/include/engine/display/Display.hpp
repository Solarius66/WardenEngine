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
    Display();      ///<Constructor
                    ///<
    ~Display();     ///<Destructor
                    ///<

    void draw(const QSharedPointer<IScene> &, QQueue<event> &);      ///<Display every GameObject of a scene and get each input of the player
                                                                                ///<
    void drawGameObject(const QSharedPointer<AGameObject>);                ///<Display only 1 GameObject
                                                                                ///<
private:
    void drawLayer(const QVector<QSharedPointer<AGameObject>> &) const;    ///<Display every GameObject of a Layer of a Scene
                                                                                    ///<
    QSharedPointer<IGraphicalModule> _graphicalLib;
};

#endif /* end of include guard: DISPLAY_HPP_ */
