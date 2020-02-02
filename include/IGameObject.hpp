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
    class ICollider;
    class IGameObject
    {
    public:
        IGameObject();
        virtual ~IGameObject();

        // members getters
        virtual wd::ID                  getID() const = 0;
        virtual const std::string &     getName() const = 0;
        virtual wd::LAYER               getLayer() const  = 0;
        virtual const wd::ITransform &  getTransform() const = 0;
        virtual const wd::ICollider &   getCollider() const = 0;
        virtual const wd::ISprite &     getSprite() const = 0;

        // members setters
        virtual void    setLayer(const wd::LAYER &);
        virtual void    setTransform(std::shared_ptr<wd::ITransform>);
        virtual void    setCollider(std::shared_ptr<wd::ICollider>);
        virtual void    setSprite(std::shared_ptr<wd::ISprite>);

        virtual void    Update(const std::vector<wd::IGameObject> &) = 0;
    };
}

#endif /* !IGAMEOBJECT_HPP */
