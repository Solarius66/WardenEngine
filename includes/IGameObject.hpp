/*
** EPITECH PROJECT, 2020
** IGameObject
** File description:
** GameObject class Interface declaration
*/

#ifndef IGAMEOBJECT_HPP
#define IGAMEOBJECT_HPP

#include <string>
#include "Enums.hpp"

namespace wd
{
    class IGameObject {
        public:
            IGameObject() = delete;
            virtual ~IGameObject();

            // members getters
            virtual const wd::ID        getID() const = 0;
            virtual const std::string   getName() const = 0;
            virtual wd::LAYER           getLayer() const  = 0;
            virtual wd::ITransform      getTransform() const = 0;
            virtual wd::ICollider       getCollider() const = 0;
            virtual wd::ISprite         getSprite() const = 0;

            // members setters
            virtual void    setLayer(const wd::LAYER &layer) = 0;
            virtual void    setTransform(const wd::ITransform &transform) = 0;
            virtual void    setCollider(const wd::ICollider &collider) = 0;
            virtual void    setSprite(const wd::ISprite &sprite) = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEOBJECT_HPP */