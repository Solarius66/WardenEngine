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
    class Vector2
    {
        public:
            Vector2(const int &xRef = 0, const int &yRef = 0);
            Vector2(const Vector2 &);
            ~Vector2();

            // operator overload to assign memebers
            Vector2 &operator=(const Vector2 &);

            // public member
            int x;
            int y;
    };
}

#pragma pack(pop)

// overload << on std::cout to print x and y

std::ostream &operator<<(std::ostream &, const wd::Vector2 &);

#endif /* !VECTOR2_HPP */