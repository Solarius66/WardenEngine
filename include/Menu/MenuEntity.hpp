/*
** EPITECH PROJECT, 2019
** MenuEntity.hpp
** File description:
** MenuEntity Class Declaration
*/

#ifndef MENUENTITY_HPP_
#define MENUENTITY_HPP_

#include "AGameObject.hpp"

namespace wd
{
    class MenuEntity : public wd::AGameObject
    {
    public:
        MenuEntity(const std::string &name, int id, int layer, float speed);
        MenuEntity(wd::MenuEntity &);
        ~MenuEntity() = default;
    };
}

#endif /* end of include guard: MENUENTITY_HPP_ */
