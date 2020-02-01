/*
** EPITECH PROJECT, 2019
** IDisplay.hpp
** File description:
** Definition of the Display Interface
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <vector>

#include "IWindow.hpp"
#include "IData.hpp"

namespace wd
{
    class IDisplay
    {
    public:
        IDisplay() = delete;
        virtual ~IDisplay();

        virtual void    draw(wd::IScene &) = 0;
        virtual void    drawGameObject(wd::IGameObject &) = 0;

    protected:
        virtual void    drawLayer(std::vector<wd::IGameObject>);
    };
}

#endif /* end of include guard: IDISPLAY_HPP_ */
