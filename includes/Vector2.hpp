/*
** EPITECH PROJECT, 2020
** Vector2
** File description:
** Vector2 template class declaration
*/

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#pragma pack(push, 1)

namespace wd
{
    template<typename T>
    class Vector2
    {
        public:
            Vector2();
            ~Vector2();

            // public member
            T   x;
            T   y;
    };
}

#pragma pack(pop)

#endif /* !VECTOR2_HPP */