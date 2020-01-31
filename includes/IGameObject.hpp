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
            IGameObject();
            ~IGameObject();

            // members getters
            virtual const wd::ID        getID() = 0 const;
            virtual const std::string   getName() = 0 const;
            virtual wd::Layer           getLayer() = 0 const;
            virtual wd::ITransform      getTransform() = 0 const;
            virtual wd::ICollider       getCollider() = 0 const;
            virtual wd::ISprite         getSprite() = 0 const;

            // members setters
            virtual void    setLayer(const wd::Layer &layer) = 0;
            virtual void    setTransform(const wd::ITransform &transform) = 0;
            virtual void    setCollider(const wd::ICollider &collider) = 0;
            virtual void    setSprite(const wd::ISprite &sprite) = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEOBJECT_HPP */