/*
** EPITECH PROJECT, 2019
** ISceneManager.hpp
** File description:
** SceneManager Interface Declaration
*/

#ifndef ISCENEMANAGER_HPP_
#define ISCENEMANAGER_HPP_

/// @file include/engine/data/ISceneManager.hpp

#include <QSharedPointer>

#include "include/engine/data/IScene.hpp"

///
/// SceneManager Interface Implementation
///
class ISceneManager
{
public:
    ///<Constructor
    ISceneManager() = default; ///<

    ///<Destructor
    virtual ~ISceneManager() = default; ///<

    ///<Switch active Scene
    virtual void sceneSwap(const QString &) = 0; ///<

    ///<Add a Scene to the list of Scenes
    virtual void addScene(const QSharedPointer<IScene> &) = 0; ///<

    ///<Remove a Scene from the list of Scenes
    virtual void removeScene(const QString &) = 0; ///<

    ///<Return the Scene currently used
    virtual const QSharedPointer<IScene> &getActiveScene() = 0; ///<
};

#endif /* end of include guard: ISCENEMANAGER_HPP_ */
