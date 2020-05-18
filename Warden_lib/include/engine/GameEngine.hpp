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
    GameEngine();   ///<Constructor
                    ///<
    ~GameEngine();  ///<Destructor
                    ///<

    void loop();    ///<Engine Loop
                    ///<

private:
    QSharedPointer<IDisplay>        _displayModule; ///<Display Module Pointer
                                                    ///<
    QSharedPointer<ISceneManager>   _dataModule;    ///<SceneManager Module Pointer
                                                    ///<
    QSharedPointer<ICore>           _coreModule;    ///<Core Module Pointer
                                                    ///<
    QQueue<event>                   _events;        ///<Event Queue
                                                    ///<
};

#endif /* end of include guard: GAMEENGINE_HPP_ */
