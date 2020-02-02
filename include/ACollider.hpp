/*
** EPITECH PROJECT, 2020
** ACollider
** File description:
** ACollider abstract class declaration
*/

#ifndef ACOLLIDER_HPP
#define ACOLLIDER_HPP

#include <ostream>
#include "ICollider.hpp"

#pragma pack(push, 1)

namespace wd
{
    class ACollider : public wd::ICollider {
        public:
            ACollider();
            ACollider(const wd::ACollider &);
            ~ACollider();

            // members getters
            bool    getIsCollide() const {return _isCollide;}

            // members setters
            void    setIsCollide(const bool &);

            // trigger collider functions
            virtual void    onTriggerEnter();
            virtual void    onTriggerExit();
            virtual void    onTriggerStay();

            // Update member function
            virtual void    Update(const std::vector<std::shared_ptr<wd::IGameObject>> &);

            // overloads on operators
            virtual wd::ACollider    &operator=(const wd::ACollider &);

        private:
            bool    _isCollide;
    };
}

#pragma pack(pop)

std::ostream &operator<<(std::ostream &, const wd::ACollider &);

#endif /* !COLLIDER_HPP */
