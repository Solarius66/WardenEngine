/*
** EPITECH PROJECT, 2019
** SceneManager.hpp
** File description:
** SceneManager Class Declaration
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

/// @file include/engine/data/SceneManager.hpp

#include "ISceneManager.hpp"

namespace wd
{
    ///
    /// SceneManager Class, contain the Scenes Map and a key to access to the Active Scene
    ///
    class SceneManager : public wd::ISceneManager
    {
    public:
        SceneManager();     ///<Constructor
                            ///<
        ~SceneManager();    ///<Destructor
                            ///<

        void                            sceneSwap(const std::string &);                 ///<Switch active Scene
                                                                                        ///<
        void                            addScene(const std::shared_ptr<wd::IScene> &);  ///<Add a Scene to the list of Scenes
                                                                                        ///<
        void                            removeScene(const std::string &);               ///<Remove a Scene from the list of Scenes
                                                                                        ///<
        const std::shared_ptr<wd::IScene> &   getActiveScene();                               ///<Return the Scene currently used
                                                                                        ///<
        void                            switchScene(int);                               ///<Switch to next or previous Scene, depending of value ataken as parameter
                                                                                        ///<

    private:
        std::map<std::string, std::shared_ptr<wd::IScene>>  _scenes;        ///<Map of the IScene
                                                                            ///<
        std::string                                         _activeScene;   ///<Key corresponding to the active Scene
                                                                            ///<
    };
}

#endif /* end of include guard: SCENEMANAGER_HPP_ */
