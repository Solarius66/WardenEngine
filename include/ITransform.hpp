/*
** EPITECH PROJECT, 2020
** ITransform
** File description:
** Transform class Interface declaration
*/

#ifndef ITRANSFORM_HPP
#define ITRANSFORM_HPP

#include "Vector2int.hpp"

namespace wd
{
    class ITransform
    {
        public:
            ITransform() = delete;
            virtual ~ITransform();

            // members getters
            virtual wd::Vector2int  getPosition() const = 0;
            virtual wd::Vector2int  getScale() const = 0;
            virtual float           getRotation() const = 0;

            // members setters
            virtual void    setPosition(wd::Vector2int) = 0;
            virtual void    setScale(wd::Vector2int) = 0;
            virtual float   setRotation(float) = 0;

            // Update member function
            virtual void    Update() = 0;
    };
}

#endif /* !ITRANSFORM_HPP */
