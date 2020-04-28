/*
** EPITECH PROJECT, 2019
** ISceneManager.hpp
** File description:
** SceneManager Interface Declaration
*/

#ifndef ISCENEMANAGER_HPP_
#define ISCENEMANAGER_HPP_

/// @file include/engine/data/ISceneManager.hpp

#include <string>
#include <memory>

#include "IScene.hpp"

namespace wd
{
    ///
    /// SceneManager Interface Implementation
    ///
    class ISceneManager
    {
    public:
        ISceneManager() = default;              ///<Constructor
                                        ///<
        virtual ~ISceneManager() = default;     ///<Destructor
                                        ///<

        virtual void                            sceneSwap(const std::string &) = 0;                 ///<Switch active Scene
                                                                                                    ///<
        virtual void                            addScene(const std::shared_ptr<wd::IScene> &) = 0;  ///<Add a Scene to the list of Scenes
                                                                                                    ///<
        virtual void                            removeScene(const std::string &) = 0;               ///<Remove a Scene from the list of Scenes
                                                                                                    ///<
        virtual const std::shared_ptr<wd::IScene> &   getActiveScene() = 0;                         ///<Return the Scene currently used
                                                                                                    ///<
        virtual void                            switchScene(int) = 0;                               ///<Switch to next or previous Scene, depending of value ataken as parameter
                                                                                                    ///<
    };
}

#endif /* end of include guard: ISCENEMANAGER_HPP_ */
