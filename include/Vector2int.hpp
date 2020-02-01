/*
** EPITECH PROJECT, 2020
** Vector2int
** File description:
** Vector2int template class declaration
*/

#ifndef VECTOR2INT_HPP
#define VECTOR2INT_HPP

#include <ostream>

#pragma pack(push, 1)

namespace wd
{
    class Vector2int
    {
        public:
            Vector2int(const int &xRef = 0, const int &yRef = 0);
            Vector2int(const Vector2int &);
            ~Vector2int();

            // operator overload to assign memebers
            Vector2int &operator=(const Vector2int &);

            // public member
            int x;
            int y;
    };
}

#pragma pack(pop)

// overload << on std::cout to print x and y

std::ostream &operator<<(std::ostream &, const wd::Vector2int &);

#endif /* !VECTOR2INT_HPP */
