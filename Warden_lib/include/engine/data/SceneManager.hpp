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
    ///<Constructor
    SceneManager(); ///<
    ///<Destructor
    ~SceneManager(); ///<

    ///<Switch active Scene
    void sceneSwap(const QString &); ///<

    ///<Add a Scene to the list of Scenes
    void addScene(const QSharedPointer<IScene> &); ///<

    ///<Remove a Scene from the list of Scenes
    void removeScene(const QString &); ///<

    ///<Return the Scene currently used
    const QSharedPointer<IScene> &getActiveScene(); ///<

private:
    ///<Map of the IScene
    QMap<QString, QSharedPointer<IScene>> _scenes; ///<

    ///<Key corresponding to the active Scene
    QString _activeScene; ///<
};

#endif /* end of include guard: SCENEMANAGER_HPP_ */
