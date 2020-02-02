/*
** EPITECH PROJECT, 2020
** ATransform
** File description:
** ATransform abstract class declaration
*/

#ifndef ATRANSFORM_HPP
#define ATRANSFORM_HPP

#include <ostream>
#include "ITransform.hpp"
#include "Vector2int.hpp"

#pragma pack(push, 1)

namespace wd
{
    class ATransform : public ITransform
    {
        public:
            ATransform();
            ATransform(const wd::ATransform &);
            ~ATransform();

            // members getters
            wd::Vector2int  getPosition() const {return _position;}
            wd::Vector2int  getScale() const {return _scale;}
            float           getRotation() const {return _rotation;}

            // members setters
            void    setPosition(const wd::Vector2int &);
            void    setScale(const wd::Vector2int &);
            void    setRotation(const float &);

            // Update member function
            virtual void    Update();

            // overloads on operators
            virtual wd::ATransform &operator=(const wd::ATransform &);

        protected:
            wd::Vector2int  _position;
            wd::Vector2int  _scale;
            float           _rotation;
    };
}

#pragma pack(pop)

std::ostream &operator<<(std::ostream &, const wd::ATransform &);

#endif /* !TRANSFORM_HPP */
