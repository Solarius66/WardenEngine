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
    ACollider(QSharedPointer<AGameObject>, const QSharedPointer<IScene> &); ///<Constructor, take a shared_ptr to AGameObject and a vector as Parameter, corresponding at 'This' & the AGameObject vector of the Scene
                                                                                    ///<
    ~ACollider();                                                                   ///<Destructor
                                                                                    ///<

    void update(event) final;                                       ///<Call the update function
                                                                        ///<


protected:
    virtual void onTriggerEnter(QSharedPointer<AGameObject>);  ///<Called when a AGameObject Collide the AGameObject containing this component
                                                                    ///<
    virtual void onTriggerStay(QSharedPointer<AGameObject>);   ///<Called when a AGameObject is Colliding the AGameObject containing this component
                                                                    ///<
    virtual void onTriggerExit(QSharedPointer<AGameObject>);   ///<Called when a AGameObject stop to Collide the AGameObject containing this component
                                                                    ///<
    QSharedPointer<AGameObject>                _this;
    QSharedPointer<IScene>                     _scene;

private:
    QMap<QString, bool> _isCollide;
};

#endif /* end of include guard: ACOLLIDER_HPP_ */
