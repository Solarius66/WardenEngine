/*
** EPITECH PROJECT, 2020
** Transform
** File description:
** Transform class declaration
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <ostream>
#include "ITransform.hpp"
#include "Vector2.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Transform : public ITransform
    {
        public:
            Transform();
            Transform(const wd::Transform &);
            ~Transform();

            // members getters
            virtual wd::Vector2int  getPosition() const {return _position;}
            virtual wd::Vector2int  getScale() const {return _scale;}
            virtual float           getRotation() const {return _rotation;}

            // members setters
            void    setPosition(const wd::Vector2int &);
            void    setScale(const wd::Vector2int &);
            float   setRotation(const float &);

            // Update member function
            void    Update();

            // overloads on operators
            wd::Transform &operator=(const wd::Transform &);

        private:
            wd::Vector2int     _position;
            wd::Vector2int     _scale;
            float           _rotation;
    };
}

#pragma pack(pop)

std::ostream &operator<<(std::ostream &, const wd::Transform &);

#endif /* !TRANSFORM_HPP */