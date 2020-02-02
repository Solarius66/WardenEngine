/*
** EPITECH PROJECT, 2020
** IGameObject
** File description:
** GameObject class Interface declaration
*/

#ifndef IGAMEOBJECT_HPP
#define IGAMEOBJECT_HPP

#include <string>
#include "ITransform.hpp"
#include "ICollider.hpp"
#include "ISprite.hpp"
#include "Enums.hpp"

namespace wd
{
    class IGameObject
    {
        public:
            IGameObject();
            virtual ~IGameObject();

            // members getters
            virtual const wd::ID        getID() const = 0;
            virtual const std::string   getName() const = 0;
            virtual wd::LAYER           getLayer() const  = 0;
            virtual wd::ITransform      getTransform() const = 0;
            virtual wd::ICollider       getCollider() const = 0;
            virtual wd::ISprite         getSprite() const = 0;

            // members setters
            virtual void    setLayer(const wd::LAYER &) = 0;
            virtual void    setTransform(const wd::ITransform &) = 0;
            virtual void    setCollider(const wd::ICollider &) = 0;
            virtual void    setSprite(const wd::ISprite &) = 0;

            virtual void    Update(const std::vector<wd::IGameObject> &) = 0;
    };
}

#endif /* !IGAMEOBJECT_HPP */
