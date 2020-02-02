/*
** EPITECH PROJECT, 2020
** AGameObject
** File description:
** GameObject abstract class declaration
*/

#ifndef AGAMEOBJECT_HPP
#define AGAMEOBJECT_HPP

#include <ostream>
#include <string>
#include "IGameObject.hpp"
#include "ITransform.hpp"
#include "ICollider.hpp"
#include "ISprite.hpp"
#include "Enums.hpp"

#pragma pack(push, 1)

namespace wd
{
    class AGameObject : public IGameObject
    {
        public:
            AGameObject(const std::string &, const wd::ID &);
            AGameObject(const wd::AGameObject &);
            ~AGameObject();

            // members getters
            const wd::ID        getID() const {return _id;}
            const std::string   getName() const {return _name;}
            wd::LAYER           getLayer() const {return _layer;}
            wd::ITransform      getTransform() const {return _transform;}
            wd::ICollider       getCollider() const {return _collider;}
            wd::ISprite         getSprite() const {return _sprite;}

            // members setters
            void    setLayer(const wd::LAYER &);
            void    setTransform(const wd::ITransform &);
            void    setCollider(const wd::ICollider &);
            void    setSprite(const wd::ISprite &);

            // Update member function called each frame
            virtual void    Update(const std::vector<wd::IGameObject> &);

            // overloads on operators
            virtual wd::AGameObject &operator=(const wd::AGameObject &);

        protected:
            const wd::ID        _id;
            const std::string   _name;
            wd::LAYER           _layer;
            wd::ITransform      _transform;
            wd::ICollider       _collider;
            wd::ISprite         _sprite;
    };
}

#pragma pack(pop)

std::ostream &operator<<(std::ostream &, const wd::AGameObject &);

#endif /* !AGAMEOBJECT_HPP */
