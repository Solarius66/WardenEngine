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
    template<typename T>
    class Transform : public ITransform
    {
        public:
            Transform();
            Transform(const wd::Transform &ref) : _position(ref._position), _scale(ref._scale), _rotation(ref._rotation)
            ~Transform();

            // members getters
            virtual wd::Vector2<T>  getPosition() const {return _position;}
            virtual wd::Vector2<T>  getScale() const {return _scale;}
            virtual float           getRotation() const {return _rotation;}

            // members setters
            void    setPosition(wd::Vector2<T> position) {_position = position;}
            void    setScale(wd::Vector2<T> scale) {_scale = scale;}
            float   setRotation(float rotation) {_rotation = rotation;}

            // update member function
            void    update() {}

            // overloads on operators
            wd::Transform &operator=(const wd::Transform &ref) {_position = ref._position; _scale = ref._scale; _rotation = ref._rotation;}

        private:
            wd::Vector2<T>  _position;
            wd::Vector2<T>  _scale;
            float           _rotation
    };
}

#pragma pack(pop)

template<typename T>
std::ostream &operator<<(std::ostream &os, const wd::Transform<T> &transform) {return os << "Position: " << transform.getPosition() << std::endl << "Scale: " << transform.getScale() << std::endl << "Rotation: " << transform.getRotation();}

#endif /* !TRANSFORM_HPP */