/*
** EPITECH PROJECT, 2019
** MenuScene.hpp
** File description:
** MenuScene Class Declaration
*/

#ifndef MENUSCENE_HPP_
#define MENUSCENE_HPP_

#include "AScene.hpp"

namespace wd
{
    class MenuScene : public wd::AScene
    {
    public:
        MenuScene();
        ~MenuScene() = default;

        void reset();

    private:
        void build();
    };
}

#endif /* end of include guard: MENUSCENE_HPP_ */
