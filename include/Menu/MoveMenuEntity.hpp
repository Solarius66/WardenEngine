/*
** EPITECH PROJECT, 2018
** MoveMenuEntity.hpp
** File description:
** header
*/

#ifndef MOVEMENUENTITY_HPP_
#define MOVEMENUENTITY_HPP_

#include "AComponent.hpp"
#include "Event.hpp"
#include "MenuEntity.hpp"
#include "AGameObject.hpp"

namespace wd
{
    class MoveMenuEntity : public wd::AComponent
    {
    public:
        MoveMenuEntity(const std::shared_ptr<wd::MenuEntity> &obj, float speed);
        ~MoveMenuEntity() = default;

        void update(wd::event);
    private:
        std::shared_ptr<wd::AGameObject>    _obj;
        float                               _speed;
        std::chrono::time_point<std::chrono::steady_clock> _start;
    };
}

#endif /* end of include guard: MOVEMENUENTITY_HPP_ */
