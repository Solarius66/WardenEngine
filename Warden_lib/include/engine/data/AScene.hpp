/*
** EPITECH PROJECT, 2019
** AScene.hpp
** File description:
** AScene Class Declaration
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

/// @file include/engine/data/AScene.hpp

#include <QSharedPointer>
#include <QVector>
#include <QJsonObject>

#include "include/engine/data/AGameObject.hpp"
#include "include/engine/data/IScene.hpp"

///
/// AScene Class, contain the AGameObject Vector and the Name of the scene
///
class AScene : public IScene
{
public:
    ///<Constructor
    AScene(const QString &); ///<

    ///<Destructor
    ~AScene(); ///<

    ///<Return a vector containing all AGameObjects from a Layer specified as parameter
    QVector<QSharedPointer<AGameObject>> getFromLayer(int); ///<

    ///<Return a vector containing all AGameObjects from an ID specified as parameter
    QVector<QSharedPointer<AGameObject>> getFromID(int); ///<

    ///<Return a Shared_ptr pointing to a AGameObject which name is specified as parameter
    QSharedPointer<AGameObject> &getFromName(const QString &); ///<

    ///<Return the vector of AGameObject
    QVector<QSharedPointer<AGameObject>> getObjects() {return _objects;} ///<

    ///<Return the name of the AScene
    const QString &getName() const; ///<

    ///<Return the Score of the Scene
    virtual int getScore() {return _score;} ///<

    ///<Return the Score of the Scene
    virtual void setScore(int score) {_score = score;} ///<

    ///<Call update() of every AGameObject contained in the IAScene
    bool    update(event); ///<

    ///<Add a AGameObject to the vector of the AScene
    void    addObject(const QSharedPointer<AGameObject> &); ///<

    ///<Remove a AGameObject from the vector, which name is specified as parameter
    void    destroyGameObjectFromName(const QString &); ///<

    ///<Remove a AGameObject from the vector, which name is specified as parameter
    void    destroyGameObject(); ///<

    ///<Reset the scene as made in the constructor
    virtual void reset() {} ///<

    ///<Load a scene from a .json object
    void read(const QJsonObject &json); ///<

    ///<Save a scene in a .json object
    void write(QJsonObject &json) const; ///<

    ///<Display Name of every AGameObject contained in the AScene (Used for debugging)
    void    debug(); ///<

protected:
    ///<Vector of the AGameObject
    QVector<QSharedPointer<AGameObject>> _objects; ///<

    ///<Is the scene running
    bool _state; ///<

private:
    ///<Name of the AScene
    QString _name; ///<

    ///<Score of the Scene
    int _score = 0; ///<
};

#endif /* end of include guard: ASCENE_HPP_ */
