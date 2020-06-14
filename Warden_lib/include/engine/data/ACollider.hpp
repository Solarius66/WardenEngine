/*
** EPITECH PROJECT, 2019
** ACollider.hpp
** File description:
** ACollider Class Declaration
*/

#ifndef ACOLLIDER_HPP_
#define ACOLLIDER_HPP_

/// @file include/engine/data/ACollider.hpp

#include <QSharedPointer>

#include "include/engine/data/AComponent.hpp"
#include "include/engine/data/AGameObject.hpp"
#include "include/engine/data/IScene.hpp"

///
/// ACollider Class, contain a vector of AGameObject in the Scene\n
/// To create a Collider, create a class which inherit from this one, and implement your own version of onTrigger* member functions
///
class ACollider : public AComponent
{
public:
    ///<Constructor, take a shared_ptr to AGameObject and a vector as Parameter, corresponding at 'This' & the AGameObject vector of the Scene
    ACollider(QSharedPointer<AGameObject>, const QSharedPointer<IScene> &); ///<

    ///<Destructor
    ~ACollider(); ///<

    ///<Call the update function
    void update(event) final; ///<

    ///<Load a component from a .json object
    void read(const QJsonObject &json); ///<

    ///<Save a component in a .json object
    void write(QJsonObject &json) const; ///<

protected:
    ///<Called when a AGameObject Collide the AGameObject containing this component
    virtual void onTriggerEnter(QSharedPointer<AGameObject>); ///<

    ///<Called when a AGameObject is Colliding the AGameObject containing this component
    virtual void onTriggerStay(QSharedPointer<AGameObject>); ///<

    ///<Called when a AGameObject stop to Collide the AGameObject containing this component
    virtual void onTriggerExit(QSharedPointer<AGameObject>); ///<

    QSharedPointer<AGameObject>                _this;
    QSharedPointer<IScene>                     _scene;

private:
    QMap<QString, bool> _isCollide;
};

#endif /* end of include guard: ACOLLIDER_HPP_ */
