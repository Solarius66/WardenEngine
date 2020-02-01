/*
** EPITECH PROJECT, 2020
** Vector2
** File description:
** Vector2 template class declaration
*/

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <ostream>

#pragma pack(push, 1)

namespace wd
{
    template<typename T>
    class Vector2
    {
        public:
            Vector2();
            Vector2(const Vector2 &ref) : x(ref.x), y(ref.y)
            ~Vector2();

            // operator overload to assign memebers
            Vector2 &operator=(const Vector2 &ref) {x = ref.x; y = ref.y; return *this;}

            // public member
            T   x;
            T   y;
    };
}

// overload << on std::cout to print x and y

std::ostream &operator<<(std::ostream &os, const wd::Vector2 &vector) {return os << "x:" << vector.x << " y:" << vector.y;}

#pragma pack(pop)

#endif /* !VECTOR2_HPP */