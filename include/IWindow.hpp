/*
** EPITECH PROJECT, 2018
** IWindow.hpp
** File description:
** header
*/
/*
** EPITECH PROJECT, 2019
** IWindow.hpp
** File description:
** Definition of the Window Interface
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include <string>

#include "IGameObject.hpp"

namespace wd
{
    class IWindow
    {
        IWindow() = delete;
        virtual ~IWindow();

        // members getter
        virtual const std::string & getTitle() const = 0;

        virtual void    setFrameRate(int) = 0;
        virtual void    draw(const wd::IGameObject &) const = 0;
    };
}

#endif /* end of include guard: IWINDOW_HPP_ */
