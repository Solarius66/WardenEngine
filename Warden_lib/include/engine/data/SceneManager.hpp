/*
** EPITECH PROJECT, 2019
** SceneManager.hpp
** File description:
** SceneManager Class Declaration
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

/// @file include/engine/data/SceneManager.hpp

#include <QSharedPointer>

#include "include/engine/data/ISceneManager.hpp"

///
/// SceneManager Class, contain the Scenes Map and a key to access to the Active Scene
///
class SceneManager : public ISceneManager
{
public:
    SceneManager();     ///<Constructor
                        ///<
    ~SceneManager();    ///<Destructor
                        ///<

    void                            sceneSwap(const QString &);                     ///<Switch active Scene
                                                                                    ///<
    void                            addScene(const QSharedPointer<IScene> &);   ///<Add a Scene to the list of Scenes
                                                                                    ///<
    void                            removeScene(const QString &);                   ///<Remove a Scene from the list of Scenes
                                                                                    ///<
    const QSharedPointer<IScene> &   getActiveScene();                               ///<Return the Scene currently used
                                                                                    ///<

private:
    QMap<QString, QSharedPointer<IScene>>       _scenes;        ///<Map of the IScene
                                                                    ///<
    QString                                         _activeScene;   ///<Key corresponding to the active Scene
                                                                    ///<
};

#endif /* end of include guard: SCENEMANAGER_HPP_ */
