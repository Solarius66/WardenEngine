/*
** EPITECH PROJECT, 2019
** GameEngine.hpp
** File description:
** GameEngine Class Declaration
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

/// @file include/engine/GameEngine.hpp

#include <queue>

#include "ISceneManager.hpp"
#include "IDisplay.hpp"
#include "ICore.hpp"
#include "Event.hpp"

///
/// wd stands for WarDen engine, it is used on every element of the Engine
///
namespace wd
{
    ///
    /// GameEngine Class, Contain all of the Engine
    ///
    class GameEngine
    {
    public:
        GameEngine();    ///<Constructor
                                            ///<
        ~GameEngine();                      ///<Destructor
                                            ///<

        void loop();   ///<Engine Loop
                        ///<

    private:
        std::unique_ptr<wd::IDisplay>   _displayModule;         ///<Display Module Pointer
                                                                ///<
        std::unique_ptr<wd::ISceneManager>  _dataModule;        ///<SceneManager Module Pointer
                                                                ///<
        std::unique_ptr<wd::ICore>      _coreModule;            ///<Core Module Pointer
                                                                ///<
        std::queue<wd::event>           _events;                ///<Event Queue
                                                                ///<
    };
}

#endif /* end of include guard: GAMEENGINE_HPP_ */
