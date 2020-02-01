/*
** EPITECH PROJECT, 2019
** Window.hpp
** File description:
** Definition of the Window Class
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "IWindow.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Window : public wd::IWindow
    {
    public:
        Window(const std::string &);
        ~Window() = default;

        // Members getter
        const std::string &getTitle() const {return _title}

        // Members setter
        void setFrameRate(int);

        void draw(const wd::IGameObject &) const;

    private:
        sf::RenderWindow    _window;
        sf::VideoMode       _mode;
        std::string         _title;
        unsigned int        _frameRate = 60;
    };
}

#pragma pack(pop)

#endif /* end of include guard: WINDOW_HPP_ */
