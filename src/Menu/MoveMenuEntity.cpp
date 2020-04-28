/*
** EPITECH PROJECT, 2019
** MoveMenuEntity.cpp
** File description:
** MoveMenuEntity Class Implementation
*/

#include <ctime>
#include <chrono>

#include "MoveMenuEntity.hpp"
#include "Transform.hpp"

wd::MoveMenuEntity::MoveMenuEntity(const std::shared_ptr<wd::MenuEntity> &obj, float speed) : AComponent("MoveMenuEntity")
{
    std::chrono::steady_clock sc;
    _obj = obj;
    _speed = speed;
    _start = sc.now();
    _obj->getComponent<wd::Transform>("Transform").setSize(2, 2, 2);
}

void wd::MoveMenuEntity::update(wd::event event)
{
    static_cast<void>(event);
    std::chrono::steady_clock sc;
    auto time_span = static_cast<std::chrono::duration<double>>(sc.now() - _start);
    if (time_span.count() > _speed / 50) {
        _obj->getComponent<wd::Transform>("Transform").translate(0.1);
        _obj->getComponent<wd::Transform>("Transform").rotate(0, 0, _speed * 2);
        _start = sc.now();
    }
    if (_obj->getComponent<wd::Transform>("Transform").getPosition().x >= 23)
        _obj->getComponent<wd::Transform>("Transform").setPosition(- (rand() % 10), rand() % 26, 0);
}
