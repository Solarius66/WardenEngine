/*
** EPITECH PROJECT, 2019
** ScoreManager.hpp
** File description:
** ScoreManager Class Declaration
*/

#ifndef SCOREMANAGER_HPP_
#define SCOREMANAGER_HPP_

#include "AComponent.hpp"
#include "AGameObject.hpp"

namespace wd
{
    class ScoreManager : public wd::AComponent
    {
    public:
        ScoreManager(int value, const std::shared_ptr<wd::AGameObject> &obj);
        ~ScoreManager() = default;
    };
}

#endif /* end of include guard: SCOREMANAGER_HPP_ */
