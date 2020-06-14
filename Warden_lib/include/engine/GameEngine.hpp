/*
** EPITECH PROJECT, 2019
** GameEngine.hpp
** File description:
** GameEngine Class Declaration
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

/// @file include/engine/GameEngine.hpp

#include <QSharedPointer>
#include <QQueue>

#include "include/engine/sound/ISound.hpp"
#include "include/engine/display/IDisplay.hpp"
#include "include/engine/core/ICore.hpp"
#include "include/engine/data/ISceneManager.hpp"
#include "include/engine/Event.hpp"

///
/// GameEngine Class, Contain all of the Engine
///
class GameEngine
{
public:
    ///<Constructor
    GameEngine(); ///<

    ///<Destructor
    ~GameEngine(); ///<

    ///<Engine Loop
    void loop(); ///<

private:
    ///<Display Module Pointer
    QSharedPointer<IDisplay> _displayModule; ///<

    ///<SceneManager Module Pointer
    QSharedPointer<ISceneManager> _dataModule; ///<

    ///<Core Module Pointer
    QSharedPointer<ICore> _coreModule; ///<

    ///<Event Queue
    QQueue<event> _events; ///<

    ///<Sound Module Pointer
    QSharedPointer<ISound> _soundModule; ///<
};

#endif /* end of include guard: GAMEENGINE_HPP_ */
