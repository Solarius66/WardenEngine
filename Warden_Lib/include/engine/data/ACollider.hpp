/*
** EPITECH PROJECT, 2019
** ACollider.hpp
** File description:
** ACollider Class Declaration
*/

#ifndef ACOLLIDER_HPP_
#define ACOLLIDER_HPP_

/// @file include/engine/data/ACollider.hpp

#include <memory>
#include <vector>

#include "AComponent.hpp"
#include "AGameObject.hpp"
#include "IScene.hpp"

namespace wd
{
    ///
    /// ACollider Class, contain a vector of AGameObject in the Scene\n
    /// To create a Collider, create a class which inherit from this one, and implement your own version of onTrigger* member functions
    ///
    class ACollider : public wd::AComponent
    {
    public:
        ACollider(std::shared_ptr<wd::AGameObject>, const std::shared_ptr<wd::IScene> &); ///<Constructor, take a shared_ptr to AGameObject and a vector as Parameter, corresponding at 'This' & the AGameObject vector of the Scene
                                                                                                            ///<
        ~ACollider();                                                                                       ///<Destructor
                                                                                                            ///<

        void update(wd::event) final;                                       ///<Call the update function
                                                                            ///<


    protected:
        virtual void onTriggerEnter(std::shared_ptr<wd::AGameObject>);  ///<Called when a AGameObject Collide the AGameObject containing this component
                                                                        ///<
        virtual void onTriggerStay(std::shared_ptr<wd::AGameObject>);   ///<Called when a AGameObject is Colliding the AGameObject containing this component
                                                                        ///<
        virtual void onTriggerExit(std::shared_ptr<wd::AGameObject>);   ///<Called when a AGameObject stop to Collide the AGameObject containing this component
                                                                        ///<
        std::shared_ptr<wd::AGameObject>                _this;
        std::shared_ptr<wd::IScene>                     _scene;

    private:
        std::map<std::string, bool> _isCollide;
    };
}

#endif /* end of include guard: ACOLLIDER_HPP_ */
