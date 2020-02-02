/*
** EPITECH PROJECT, 2020
** ICollider
** File description:
** Collider class Interface declaration
*/

#ifndef ICOLLIDER_HPP
#define ICOLLIDER_HPP

#include <vector>

#include "IGameObject.hpp"

namespace wd
{
    class IGameObject;
    class ICollider
    {
    public:
        ICollider();
        virtual ~ICollider();

        // members getters
        virtual bool    getIsCollide() const = 0;

        // members setters
        virtual void    setIsCollide(bool) = 0;

        // trigger collider functions
        virtual void    onTriggerEnter() = 0;
        virtual void    onTriggerExit() = 0;
        virtual void    onTriggerStay() = 0;

        // Update member function
        virtual void    Update(const std::vector<wd::IGameObject> &) = 0;
    };
}

#endif /* !ICOLLIDER_HPP */
