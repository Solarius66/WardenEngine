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
        Window(const std::string &, int x = 0, int y = 0);
        ~Window() = default;

        // Members getter
        const std::string &getTitle() const {return _title;}

        // Members setter
        void setFrameRate(unsigned int);

        void draw(const std::shared_ptr<wd::IGameObject> &);

    private:
        sf::VideoMode       _mode;
        sf::RenderWindow    _window;
        std::string         _title;
        unsigned int        _frameRate = 60;
    };
}

#pragma pack(pop)

#endif /* end of include guard: WINDOW_HPP_ */
