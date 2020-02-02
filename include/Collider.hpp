/*
** EPITECH PROJECT, 2020
** Collider
** File description:
** Collider class declaration
*/

#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include <ostream>
#include "ICollider.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Collider : public wd::ICollider {
        public:
            Collider();
            Collider(const wd::Collider &);
            ~Collider();

            // members getters
            bool    getIsCollide() const {return _isCollide;}

            // members setters
            void    setIsCollide(const bool &);

            // trigger collider functions
            void    onTriggerEnter();
            void    onTriggerExit();
            void    onTriggerStay();

            // Update member function
            void    Update();

            // overloads on operators
            wd::Collider    &operator=(const wd::Collider &);

        private:
            bool    _isCollide;
    };
}

#pragma pack(pop)

std::ostream &operator<<(std::ostream &, const wd::Collider &);

#endif /* !COLLIDER_HPP */